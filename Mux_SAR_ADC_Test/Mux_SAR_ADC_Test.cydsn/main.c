/* ========================================
 *
 * Copyright YOUR COMPANY, THE YEAR
 * All Rights Reserved
 * UNPUBLISHED, LICENSED SOFTWARE.
 *
 * CONFIDENTIAL AND PROPRIETARY INFORMATION
 * WHICH IS THE PROPERTY OF your company.
 *
 * ========================================
*/

#include <devices.h>

/*******************************************************************************
* File: main.c
*
* Version: 3.0
*
* Description:
*   This is a basic design source code.
*
********************************************************************************/

/* Variable declarations for DMA_1 */
uint8 DMA_1_Chan;
uint8 DMA_1_TD[1];

	/* Compare the values extracted from the ADC using DMA, memcpy and using the API */
	 int16 DMAADCResultArray[ADC_SAR_Seq_1_NUMBER_OF_CHANNELS] = {0};   // *** CHANGED FROM UINT16 ****
	 int16 MEMCPYResultArray[ADC_SAR_Seq_1_NUMBER_OF_CHANNELS] = {0};   // *** CHANGED FROM UINT16 ****
	 int16 APIFUNResultArray[ADC_SAR_Seq_1_NUMBER_OF_CHANNELS] = {0};   // *** CHANGED FROM UINT16 ****


/* DMA Configuration for DMA_1 */
#define DMA_BYTES_PER_BURST 2*ADC_SAR_Seq_1_NUMBER_OF_CHANNELS	//Each TD handles all channels, 1 16-bit value each
#define DMA_REQUEST_PER_BURST 1
#define DMA_SRC_BASE (CYDEV_SRAM_BASE)	//Regular ADCs result is DMA'd from the Peripheral Spoke. The sequencer ADC results are internally DMA'd to an array in SRAM. Results can be DMA'd from there.
#define DMA_DST_BASE (CYDEV_SRAM_BASE)

/* The number of samples of each channel to capture */
#define NumRepsToCapture 100

/* Interrupt Flag */
volatile uint8 DMADone;

/*******************************************************************************
* Function Name: main
********************************************************************************
* Summary:
* Main function performs following functions:
* 1: Start the clock
* 2: Start the Timer
* 3: Start the interrupts
* 4: Start ADC DelSig and its interrupts
* 5: Testing for sample available from ADC
* 6: Storing the sample into the array
* 7: Comparing the samples
*
* Parameters:
*  None.
*
* Return:
*  None.
*
*******************************************************************************/        

int main()
{
	uint16 chan=0;
    uint16 print_nmbr;
	
	DMADone = 0;	//When the TD completed the DMA transfer this flag is set by the ISR
	
    /* Enable global interrupts */
    CyGlobalIntEnable;
    
	//////////////////////////////
	// Configure the DMA
	//////////////////////////////
    /* Initializing DMA_1 */
    DMA_1_Chan = DMA_1_DmaInitialize(DMA_BYTES_PER_BURST, DMA_REQUEST_PER_BURST,
                                     HI16(DMA_SRC_BASE),  HI16(DMA_DST_BASE));

	/* Allocate a TD for each channel */
	DMA_1_TD[0] = CyDmaTdAllocate();
	
	//step through and setup each TD
	CyDmaTdSetConfiguration(DMA_1_TD[0], 
							DMA_BYTES_PER_BURST,
							DMA_DISABLE_TD,
							DMA_1__TD_TERMOUT_EN | CY_DMA_TD_INC_DST_ADR );
    
    /* Configuring the TD address for the transfer. Sequencer ADC results are stored in ADC_SAR_Seq_1_finalArray. */
    CyDmaTdSetAddress(DMA_1_TD[0], LO16((uint32)(ADC_SAR_Seq_1_finalArray)), LO16((uint32)(DMAADCResultArray)));
    
    /* Setting initial TD */
    CyDmaChSetInitialTd(DMA_1_Chan, DMA_1_TD[0]);

	//////////////////////////
	// Start Components
	//////////////////////////
	
	/* ISR Start */
	isr_1_Start();
    // isr_1_StartEx(isr_1);
    //LCD_Start();
	
    /* Enable the DMA channel */
    CyDmaChEnable(DMA_1_Chan, 1);

	/* Start the ADC */
    ADC_SAR_Seq_1_Start();
	ADC_SAR_Seq_1_IRQ_Disable();	//we're not using the internal interrupt
	ADC_SAR_Seq_1_StartConvert();
	CyDelay(1000);	//give the ADC time to settle
	
    for(;;) {
		// Capture the requested data...the DMADone flag will set when complete
		if(DMADone == 1)
		{
			//reset the DMA done flag
			DMADone = 0;
            ADC_SAR_Seq_1_StopConvert();
			
			//////////////////////////////////////////////////// 
			// Grab the result values manually for comparison:
			////////////////////////////////////////////////////
			
			// USING THE API
			/* Channel results are saved in reverse order in the results array. Store them so they appear in the results array in the same order as the DMA data.*/
//            if (ADC_SAR_Seq_1_IsEndConversion(ADC_SAR_Seq_1_WAIT_FOR_RESULT))
//            {
			for(chan = 0; chan < ADC_SAR_Seq_1_NUMBER_OF_CHANNELS; chan++)
			{
                
				APIFUNResultArray[chan] = ADC_SAR_Seq_1_CountsTo_mVolts(ADC_SAR_Seq_1_GetResult16(ADC_SAR_Seq_1_NUMBER_OF_CHANNELS-chan-1));
			}
//            }

			// USING MEMCPY
/*
 Jerry says "Why use the following line? We already have the result of the conversion in APIFUNResultArray.
    It probably won't work anyway because the sar's finalArray is probably already cleared by the GetResult16 function above.
			memcpy(MEMCPYResultArray,ADC_SAR_Seq_1_finalArray,ADC_SAR_Seq_1_NUMBER_OF_CHANNELS*sizeof(uint16));
    INSTEAD, use the following line to move data to a different array.
            
    NOTE: the ISR HAS BEEN MOVED to the eoc of the SAR. By the time you get to this line of code, the DMA is complete anyway.            
    Now that we have Read the conversion results we have the lesure of doing whatever we want with this array.
*/
			memcpy(MEMCPYResultArray, APIFUNResultArray, ADC_SAR_Seq_1_NUMBER_OF_CHANNELS*sizeof(uint16));
            
//  And if your want, do it again to move it to an offset from the MEMCPYResultArray -- say 12 bytes in? Not shown here.
//  That is, move the APIFUNResultArray anywhere you want in SRAM.
//  NOTE: We moved all the arrays out of main{} into global variables and removed the "static" class.
//       Now they are mapped into high SRAM as you can see in the Results Tab under Mux_SAR_ADC_Test.map            
            
                    /* ***  First line of LCD Screen - DO ANYTHING YOU WANT WITH THIS ARRAY  */
            //LCD_Position(0, 0); CyDelay(10);  LCD_PrintString("               ");
            //LCD_Position(0, 0);
            print_nmbr = MEMCPYResultArray[0];
            //LCD_PrintNumber(print_nmbr);
            //LCD_Position(0, 6);
            print_nmbr = MEMCPYResultArray[1];
            //LCD_PrintNumber(print_nmbr);
            //LCD_Position(0, 11);
           //print_nmbr = MEMCPYResultArray[2];
            //LCD_PrintNumber(print_nmbr);

                    /* ***  Second line of LCD Screen - ANALOG INPUT  */
            //LCD_Position(1, 0); CyDelay(10);  LCD_PrintString("               ");
            //LCD_Position(1, 0);
           //print_nmbr = APIFUNResultArray[3];
            //LCD_PrintNumber(print_nmbr);
            //LCD_Position(1, 6);
           //print_nmbr = APIFUNResultArray[3];
            //LCD_PrintNumber(print_nmbr);
            //LCD_Position(1, 11);
           //print_nmbr = APIFUNResultArray[4]; 
            //LCD_PrintNumber(print_nmbr);

			
			//////////////////////////////////////////////////////
			// Put a breakpoint at the next line so that the values in
			// the result arrays can be compared.
			//////////////////////////////////////////////////////
			
			/* Enable the DMA channel again */
    		CyDmaChEnable(DMA_1_Chan, 1);
            ADC_SAR_Seq_1_StartConvert();   // Let's go another round
		}
	}

	return 0;
}

/* [] END OF FILE */
