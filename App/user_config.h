#ifndef __USER_CONFIG_H__
#define __USER_CONFIG_H__

// <<< Use Configuration Wizard in Context Menu >>>

//	<s> ���ù��ܰ汾��
	#define UI_SW_VERSION "PMCU V5.00"

// <h> ϵͳ����
	// <o> Ƿѹ��λ����
		// <i>Ĭ��: 2
		// <0=> 2.3V
		// <1=> 2.4V
		// <2=> 2.5V
		// <3=> 2.6V
		#define CFG_SYS_UVLS           	0
	// <e> Ƿѹ��λ��ʾ
		#define CFG_SYS_UVLS_EN 		1		
	// </e>		
	// <e> ���߳�ʱ�����
		#define CFG_LONG_SLEEP_EN 			1
		// <o> ��ʱ���޶�������������ʱ��(ms)
			#define CFG_LONG_SLEEP_TIME 	3000 	
		// <h> ˯�߻���Դ����
			// <i>Ĭ��: 0x00
			// <q.7> WK_SRC_TIMER����ʱ����(�����ö�ʱʱ��)
			// <q.4> WK_SRC_MIC��MIC�¼�����(������MIC�¼��ж�)
			// <q.3> WK_SRC_CHG_FULL��������份��
			// <q.2> WK_SRC_USB��USB��λ���
			// <q.1> WK_SRC_PLUG�����ز�λ���
			// <q.0> WK_SRC_GPIO��GPIO���ػ���(������GPIO�����ж�)
			#define CFG_WK_SRC		        0x15
		// </h>	
		// <o> ��ʱ����ʱ������
			// <i> Ĭ��: 0
			// <0-127>		
			#define CFG_WK_SRC_TIME 			0 			
	// </e>
	// <e> ���Ź����ܿ���
		#define CFG_WDT_EN 			1
		// <o> ���Ź����ʱ��(ms)
			// <i> Ĭ��: 0
			// <1-1500>	
			#define CFG_WDT_TIME 	100 			
	// </e>	
	// <e> ϵͳ����
		#define CFG_SYS_LOCK_EN 			0
		// <o> ������ʽ
			// <i>Ĭ��: 0
			// <0=> ������
			// <1=> �����ϵ�����
			#define CFG_SYS_LOCK_MODE		1
		// <o> ������ʽ
			// <i>Ĭ��: 0
			// <0=> ������
			// <1=> USB����
			// <2=> ����5��
			// <3=> ��������3��
			#define CFG_SYS_UNLOCK_MODE		0
	// </e>
	// <e> ���̳�ʱ����(�����ʱ)
		#define CFG_SMOKE_TIMEOUT_EN 		1
		// <o> ���̳�ʱ����ʱ�䣨ms��
			// <i> Ĭ��: 0
			#define CFG_SMOKE_TIMEOUT_TIME 	10000 
	// </e>	
	// <h> ϵͳ�ж�����(��ʹ�õĹرգ�ʡ����ռ�)
		// <e> MIC�¼��ж�
			#define CFG_IT_MIC_EN		0
		// </e>	
		// <e> ADC��������ж�
			#define CFG_IT_ADC_EN		0
		// </e>		
		// <e> ����ж�
			#define CFG_IT_CHG_EN		0
		// </e>			
		// <e> GPIO�����ж�
			#define CFG_IT_GPIO_EN		0
		// </e>			
		// <e> PWM�����ж�
			#define CFG_IT_PWM_EN		1
		// </e>			
		// <e> MOS�쳣�ж�
			#define CFG_IT_MOS_ABN_EN	0
		// </e>		
		// <e> UART�ж�
			#define CFG_IT_UART_EN	0
		// </e>				
	// </h>			
// </h>

// <h> MIC����
	// <e> MIC ����ʹ��
		#define CFG_MIC_EN							1
		// <o> MIC����
			// <i>Ĭ��: 0
			// <0=> �������
			// <1=> �������
			// <2=> ���߿�����
			#define CFG_MIC_TYPE					2		
		// <o> ���߿�������ʹ�õ�GPIO��
			// <i>Ĭ��: 1
			// <0x01=> GPIOA��
			// <0x02=> GPIOB��
			// <0x04=> GPIOC��
			#define CFG_PIN_MIC_PORT			0x02
		// <o> ���߿�������ʹ�õ�GPIO��
			// <i>Ĭ��: 1
			// <0x01=> PIN0
			// <0x02=> PIN1
			// <0x04=> PIN2
			// <0x08=> PIN3
			#define CFG_PIN_MIC_PINNUM			0x02				
		// <e> MIC����������
			#define CFG_MIC_FIRE_EN					1
		// </e>		
		// <e> MIC�������ʹ��
			#define CFG_MIC_BLOW_EN					0			
		// </e>			
		// <h> MICģ�����
			// <o> ������ͷ��������(����)
				// <i>Ĭ��: 160nA
				// <0x00=> 160nA
				// <0x08=> 320nA
				#define CFG_MIC_MIC_CURR        	0x08
			// <o> ����MIC����ʱ��
				// <i>Ĭ��: 45ms
				// <0x00=> 45ms
				// <0x20=> 35ms
				// <0x40=> 23ms
				// <0x60=> 57ms
				#define CFG_MIC_SAMPLE_TIME        	 0x00
			// <o> ����MIC���̳�ʱʱ�䣨Ӳ����ʱ��
				// <i>Ĭ��: 20s
				// <0=> 2.5s
				// <1=> 5s
				// <2=> 10s
				// <3=> 20s
				#define CFG_MIC_INHALE_TIMEOUT		  3
			// <h> ����MIC�ж�ʹ�ܣ�ͬʱ��Ϊ˯�߻���Դ��
				// <i>Ĭ��: ����������
				// <q.7> MIC_ABNORMAL����ͷ�쳣
				// <q.6> MIC_SAMPLE����ͷ����
				// <q.5> MIC_BLOW����ͷ�����ʹ����ͷ�
				// <q.4> MIC_INHALE_TIMEOUT����ͷ������ʱ
				// <q.3> MIC_INHALE_RELEASE����ͷ�����ͷ�
				// <q.2> MIC_INHALE����ͷ����
				// <q.1> MIC_REFLESH_VALUE����ͷ��ֵ����
				#define CFG_MIC_IT		        	0x24
			// </h>
			// <o> MIC���̴�����ֵ1
				// <i> Ĭ��: 8
				// <0-31>
				#define CFG_MIC_TRIG1_THD             8
			// <o> MIC���̴�����ֵ2
				// <i> Ĭ��: 31
				// <0-255>
				#define CFG_MIC_TRIG2_THD             31
		// </h>		
		// <h> MIC��������
			// <o> ��ͷԤ�ȴ���ģʽ��δʵ��Ԥ�ȣ�
				// <i>Ĭ��: 2
				// <0x00=> �ر�
				// <0x02=> 2��					
				// <0x03=> 3��
				#define CFG_MIC_PREFIRE_CNT		0
			// <o> ��ͷ��������ģʽ��δʵ�ֻ�����
				// <i>Ĭ��: 3
				// <0x00=> �ر�
				// <0x03=> 3��
				#define CFG_MIC_MODE_SW_CNT		0
			// <o> ��ͷͯ������ģʽ
				// <i>Ĭ��: 5
				// <0x00=> �ر�
				// <0x03=> 3��
				// <0x05=> 5��
				#define CFG_MIC_LOCK_CNT		0x00	
		// </h>
	// </e>		
// </h>

// <h> ��������
	// <e> ������������
		#define CFG_KEY_EN						1
		// <o> �������ʹ�õ�GPIO��
			// <i>Ĭ��: 1
			// <0x01=> GPIOA��
			// <0x02=> GPIOB��
			// <0x04=> GPIOC��
			#define CFG_PIN_KEY_PORT			0x02
		// <o> �������ʹ�õ�GPIO��
			// <i>Ĭ��: 1
			// <0x01=> PIN0
			// <0x02=> PIN1
			// <0x04=> PIN2
			// <0x08=> PIN3
			#define CFG_PIN_KEY_PINNUM			0x08
		// <o> ����������Ч��ƽ
			// <i>Ĭ��: 0
			// <0=> �͵�ƽ��Ч
			// <1=> �ߵ�ƽ��Ч
			#define CFG_PIN_KEY_VALUE_TYPE		0			
		// <e> ����GPIO��������ж�ʹ�ܣ�����Ϊ˯�߻���Դ��
			#define CFG_PIN_IT_EN				1	
		// </e>			
		// <e> ��������������
			#define CFG_KEY_FIRE_EN				1
		// </e>
		// <o> Ԥ�ȴ���ģʽ��δʵ��Ԥ�ȣ�
			// <i>Ĭ��: 2
			// <0x00=> �ر�
			// <0x02=> 2��
			#define CFG_KEY_PREFIRE_CNT			2
		// <o> ��������ģʽ��δʵ�ֻ�����
			// <i>Ĭ��: 3
			// <0x00=> �ر�
			// <0x03=> 3��
			#define CFG_KEY_MODE_SW_CNT			3
		// <o> ͯ������ģʽ
			// <i>Ĭ��: 5
			// <0x00=> �ر�
			// <0x03=> 3��
			// <0x05=> 5��
			#define CFG_KEY_LOCK_CNT			0x05			
	// </e>
// </h>

// <h> ��ʱ������
	// <e> ����TIME0ʹ��
		// <i>Ĭ��: ʹ��
		#define CFG_TIM0_EN          1          
		// <o> ��ʱ��0�����ж�ʱ�䣨us��
			// <i> Ĭ�ϣ�1000us
			// <i> �������49000us��49ms��
			// <1-49000>
			#define CFG_TIM0_CNT           	200  
	// </e>
	// <e> ����TIME1ʹ��
		// <i>Ĭ��: ʹ��
		#define CFG_TIM1_EN          1 
			#define CFG_TIM1_MODE         	2 
		// <o> ��ʱ��1�����ж�ʱ�䣨us��
			// <i> Ĭ�ϣ�1000us
			// <i> �������49000us��49ms��
			// <1-49000>
			#define CFG_TIM1_CNT           	100  
	// </e>
// </h>

// <h> �����������
	// <o> �������·��
		// <i> Ĭ�ϣ���·
		// <1=> ���������ڲ�MOS
		// <2=> ���������ⲿMOS
		// <3=> ˫��������MOS��·
		#define CFG_VOUT_CNH_MAX           			1 
	// <h> �ڲ�MOS����
		// <h> �ڲ�MOS�쳣��������					
			// <o> �ڲ�MOS����������ֵ
				// <i>Ĭ��: 7A
				// <0=> 4A
				// <1=> 5A
				// <2=> 6A
				// <3=> 7A
				#define CFG_MOS_OCP_THD				3
			// <e> �ڲ�MOS�����������ʹ��
				#define CFG_MOS_OCP_EN				1     
			// </e>
			// <e> �ڲ�MOS������±���ʹ��
				#define CFG_MOS_OTP_EN				1    
			// </e>
		// </h>
		// <e> ����MOS��ǿ�����MOS_EXT���ƣ����ڲ�MOS������
			// <i> Ĭ��:ʧ��
			#define CFG_MOSEXT_EN				0		
			// <o> ������/��MOS���ʹ�����/�½�б��1
				// <i>Ĭ��: ���
				// <0=> ���
				// <1=> �Ͽ�
				// <2=> ����
				// <3=> ����
				#define CFG_MOS_GRADE_SPEED1            0 
			// <o> ������/��MOS���ʹ�����/�½�б��2
				// <i>Ĭ��: ���
				// <0=> б��1*1
				// <1=> б��1*2
				#define CFG_MOS_GRADE_SPEED2    		0 
		// </e>
		// <h> �ڲ�MOS�����������
			// <o> �ڲ�MOS PWM�������
				// <i> Ĭ�ϣ�61(1000Hz)
				// <i> ���Ƶ��=1000000/������ڣ��������20000��50Hz������С����20��50000Hz��
				// <20-20000>
				#define CFG_MOS_PWM_PERIOD      		20000
			// <o> �ڲ�MOS���ģʽ
				// <i>Ĭ��: ��ѹ���
				// <0=> ��ѹ
				// <1=> ��ѹ��Чֵ����������
				// <2=> ��ѹ������δʵ�֣�				
				// <3=> �㹦��
				// <4=> ����裨���£���δʵ�֣�
				#define CFG_MOS_OUT_MODE				0
			// <o> �ڲ�MOS���Ŀ��͵���mV/mW/m����
				#define CFG_MOS_OUTPUT_TARGET_LOW          2700
			// <o> �ڲ�MOS���Ŀ���е���mV/mW/m����
				#define CFG_MOS_OUTPUT_TARGET_MIDDLE       3200
			// <o> �ڲ�MOS���Ŀ��ߵ���mV/mW/m����
				#define CFG_MOS_OUTPUT_TARGET_HIGH         3700
			// <o> �ڲ�MOS���Ŀ��Ԥ�ȣ�mV/mW/m����
				#define CFG_MOS_OUTPUT_TARGET_PREFIRE      1800
			// <o> ���Ŀ�겹��������������
				#define CFG_MOS_OUTPUT_TARGET_FIX    	0				
			// <o> �ڲ�MOS������ADC������ʱ���ܿ�MOS��ͨ˲�䲻�ȶ��׶Σ�LSB=100us��
				// <i> ����ʵ�ʲ���΢��
				#define CFG_MOS_OPEN_DELAY          30
		// </h>	
	// </h>			
	// <h> �ⲿMOS���ã�˫·���ʱ���ã�
		// <h> �ⲿMOS���ؼ���GPIO���ã���ѡһ��
      // <e> �ⲿ�޲����·
				#define CFG_PIN_EXTMOS_RL_DET_NONE				0    
			// </e>
			// <e> ʹ��MOTOR�ܽ�������GPIO�����ã�
				#define CFG_PIN_EXTMOS_RL_DET_MOTOR				1    
			// </e>
			// <e> ʹ��GPIO�ܽ�����
				#define CFG_PIN_EXTMOS_RL_DET_GPIO				0    		
				// <o> ʹ�õ�GPIO��
					// <i>Ĭ��: 1
					// <0x01=> GPIOA��
					// <0x02=> GPIOB��
					// <0x04=> GPIOC��
					#define CFG_PIN_EXTMOS_RL_PORT				0x02
				// <o> ʹ�õ�GPIO��
					// <i>Ĭ��: 1
					// <0x01=> PIN0
					// <0x02=> PIN1
					// <0x04=> PIN2
					// <0x08=> PIN3
					#define CFG_PIN_EXTMOS_RL_PINNUM			0x01
			// </e>				
		// </h>		
		// <h> �ⲿMOS������Ƶ�GPIO����	
			// <o> ʹ�õ�GPIO��
				// <i>Ĭ��: 1
				// <0x01=> GPIOA��
				// <0x02=> GPIOB��
				// <0x04=> GPIOC��
				#define CFG_PIN_EXTMOS_VOUT_PORT			0x02
			// <o> ʹ�õ�GPIO��
				// <i>Ĭ��: 1
				// <0x01=> PIN0
				// <0x02=> PIN1
				// <0x04=> PIN2
				// <0x08=> PIN3
				#define CFG_PIN_EXTMOS_VOUT_PINNUM			0x02
		// </h>	
		// <h> VOUT��ѹADC�ɼ���GPIO����	
			// <o> ʹ�õ�GPIO��
				// <i>Ĭ��: 1
				// <0x02=> GPIOB��
				#define CFG_PIN_EXTMOS_ADC_PORT				0x02
			// <o> ʹ�õ�GPIO��
				// <i>Ĭ��: 1
				// <0x01=> PIN0
				// <0x02=> PIN1
				// <0x04=> PIN2
				#define CFG_PIN_EXTMOS_ADC_PINNUM			0x01
				
				#if (CFG_PIN_EXTMOS_ADC_PINNUM==0x01)
				#define CFG_EXTMOS_ADC_CHN			ADC_CHN3_GPIOB0
				#elif (CFG_PIN_EXTMOS_ADC_PINNUM==0x02) 
				#define CFG_EXTMOS_ADC_CHN			ADC_CHN4_GPIOB1
				#else
				#define CFG_EXTMOS_ADC_CHN			ADC_CHN5_GPIOB2
				#endif
		// </h>				
		// <h> �ⲿMOS�����������
			// <o> �ⲿMOS PWM�������
				// <i> ���Ƶ��=1/�������
				// <20-200>
				#define CFG_EXTMOS_PWM_PERIOD      		200
			// <o> �ⲿMOS���ģʽ
				// <i>Ĭ��: ��ѹ���
				// <0=> ��ѹ
				// <1=> ��ѹ��Чֵ����������
				#define CFG_EXTMOS_OUT_MODE				0
			// <o> �ⲿMOS���Ŀ��
				#define CFG_EXTMOS_OUTPUT_TARGET        3400	
			// <o> ���Ŀ�겹��������������
				#define CFG_EXTMOS_OUTPUT_TARGET_FIX    0					
			// <o> �ⲿMOS������ADC������ʱ���ܿ�MOS��ͨ˲�䲻�ȶ��׶Σ�LSB=100us��
				// <i> ����ʵ�ʲ���΢��
				#define CFG_EXTMOS_OPEN_DELAY          	30
		// </h>	
	// </h>		
// </h>	

// <h> �������       
	// <o> ���ú���������ISET(mA)
		// <i>Ĭ��: 5
		// <0=> 250
		// <1=> 300
		// <2=> 350
		// <3=> 400
		// <4=> 450
		// <5=> 500
		// <6=> 550
		// <7=> 600
		// <8=> 650
		// <9=> 700
		// <10=> 750
		#define CFG_CHG_ISET           	5 
	// <o> ���������ֹ����
		// <i>Ĭ��: 0
		// <0=> 20%ISET
		// <1=> 10%ISET
		#define CFG_CHG_FULL_ISET       0	
	// <e> ���������ʹ��
		// <i> ����ʱ��ͣ�䣻�����ͷţ����³��
		#define CFG_CHG_SMOKE_EN		1 
	// </e>  	
	// <e> �����(>600mA)��磬����������ʹ��
		#define CFG_CHG_SUB_CUR_EN		0 
		// <o> VBAT�������ޣ�mV��
			#define   CFG_CHG_SUB_CUR_VBAT_THD		3900				
		// <o> ���ý�������λISET(mA)
			// <i>Ĭ��: 5
			// <0=> 250
			// <1=> 300
			// <2=> 350
			// <3=> 400
			// <4=> 450
			// <5=> 500
			// <6=> 550
			// <7=> 600
			// <8=> 650
			#define CFG_CHG_SUB_CUR_ISET     		6 	
		// <o> �������ʱ�䣨LSB=10ms��
			#define CFG_CHG_SUB_CUR_TIMER 			100			
	// </e> 	
	// <e> ������(�����USB�γ�)������һ��MIC��ֵ��������Ӱ���ֵ
		#define CFG_CHG_REFLESH_MIC_VALUE_EN		1 	
	// </e> 	
	// <e> �������������
		#define CFG_CHG_FULL_BY_SOFT_EN		1 
		// <o> �����ѹ���ޣ�mV��
			#define CFG_CHG_FULL_VBAT_THD		4150	
		// <o> �����ѹ���ޣ�mV��
			#define CFG_CHG_RECHG_VBAT_THD		4050			
		// <o> ������ʱ�䣨LSB=10ms��
			#define CFG_CHG_FULL_TIMER 			60000				
	// </e> 	
// </h>

// <h> ���ؼ������
	// <e> ���ز�μ�⹦��ʹ�ܣ����ڲ�MOS֧�֣�
		// <i> Ĭ��:ʧ��
		#define CFG_RLOAD_PLUG_EN				0
	// </e>
	// <e> ���ض�·/���豣��ʹ��
		// <i> Ĭ��:ʧ��
		#define CFG_RLOAD_SHORT_PRO_EN				1	
		// <o> ��·�жϷ���˿��ֵ��m����
		#define CFG_RL_VALUE_SHORT				800 
		// <o> �����жϷ���˿��ֵ��m����
		#define CFG_RL_VALUE_LOW				800 	 		
	// </e>	
	// <e> ���ؿ�·����ʹ��
		// <i> Ĭ��:ʧ��
		#define CFG_RLOAD_OPEN_PRO_EN				0	
		// <o> �����жϷ���˿��ֵ��m����
		#define CFG_RL_VALUE_OPEN				3000  		
		// <e> �������ʱ����⸺�ؿ�·
			// <i> Ĭ��:ʧ��
			#define CFG_VOUT_DET_RL_EN				0
			// <o> ������ڣ�ms��
			// <i> ������̫С�������Ӱ������ȶ���
			#define CFG_VOUT_DET_RL_TIME           	100		
		// </e>			
	// </e>		
// </h>

// <h> �����������
	// <e> �����������ʹ��
		// <i> Ĭ��:ʧ��
		#define CFG_MOTOR_EN					0	
		// <o> ���Ĭ�����ռ�ձ�
			// <i>Ĭ��: 0
			// <0=> 0%
			// <1=> 7%
			// <2=> 13%
			// <3=> 20%
			// <4=> 27%
			// <5=> 33%
			// <6=> 40%
			// <7=> 47%
			// <8=> 53%
			// <9=> 60%
			// <10=> 67%
			// <11=> 73%
			// <12=> 80%
			// <13=> 87%
			// <14=> 93%
			// <15=> 100%
			#define CFG_MOTOR_DUTY 				0			
	// </e>	
// </h>

// <h> ��Ч��ʾ����
	// <e> LED���ܣ�����������ܶ�ѡһ��
		#define CFG_UI_LED_EN				1	
		// <o> LED������������RA1/RA2/RA3������Դʱ��Ч��
			// <i>Ĭ��: 0
			// <0x00=> 4mA
			// <0x08=> 8mA
			// <0x10=> 21mA
			// <0x18=> 29mA
			#define CFG_UI_LED_CURR       	0x00		
		// <h> LED�ܽ�����
			// <e> LED0      
				#define CFG_UI_LED0_EN					1	
				// <o> LED0ʹ�õ�GPIO��
					// <i>Ĭ��: 1
					// <0x01=> GPIOA��
					#define CFG_PIN_LED0_PORT			0x01
				// <o> LED0ʹ�õ�GPIO��
					// <i>Ĭ��: 1
					// <0x01=> PIN0
					// <0x02=> PIN1
					// <0x04=> PIN2
					// <0x08=> PIN3
					#define CFG_PIN_LED0_PINNUM			0x02
			// </e>	
			// <e> LED1      
				#define CFG_UI_LED1_EN					1	
				// <o> LED1ʹ�õ�GPIO��
					// <i>Ĭ��: 1
					// <0x01=> GPIOA��
					#define CFG_PIN_LED1_PORT			0x01
				// <o> LED1ʹ�õ�GPIO��
					// <i>Ĭ��: 1
					// <0x01=> PIN0
					// <0x02=> PIN1
					// <0x04=> PIN2
					// <0x08=> PIN3
					#define CFG_PIN_LED1_PINNUM			0x08
			// </e>	
			// <e> LED2      
				#define CFG_UI_LED2_EN					1	
				// <o> LED2ʹ�õ�GPIO��
					// <i>Ĭ��: 1
					// <0x01=> GPIOA��
					#define CFG_PIN_LED2_PORT			0x01
				// <o> LED2ʹ�õ�GPIO��
					// <i>Ĭ��: 1
					// <0x01=> PIN0
					// <0x02=> PIN1
					// <0x04=> PIN2
					// <0x08=> PIN3
					#define CFG_PIN_LED2_PINNUM			0x04
			// </e>	
			// <e> LED3      
				#define CFG_UI_LED3_EN					0	
				// <o> LED3ʹ�õ�GPIO��
					// <i>Ĭ��: 1
					// <0x01=> GPIOA��
					// <0x02=> GPIOB��
					// <0x04=> GPIOC��
					#define CFG_PIN_LED3_PORT			0x02
				// <o> LED3ʹ�õ�GPIO��
					// <i>Ĭ��: 1
					// <0x01=> PIN0
					// <0x02=> PIN1
					// <0x04=> PIN2
					// <0x08=> PIN3
					#define CFG_PIN_LED3_PINNUM			0x08
			// </e>		
			// <e> LED4      
				#define CFG_UI_LED4_EN					0	
				// <o> LED4ʹ�õ�GPIO��
					// <i>Ĭ��: 1
					// <0x01=> GPIOA��
					// <0x02=> GPIOB��
					// <0x04=> GPIOC��
					#define CFG_PIN_LED4_PORT			0x01
				// <o> LED4ʹ�õ�GPIO��
					// <i>Ĭ��: 1
					// <0x01=> PIN0
					// <0x02=> PIN1
					// <0x04=> PIN2
					// <0x08=> PIN3
					#define CFG_PIN_LED4_PINNUM			0x02
			// </e>		
			// <e> LED5      
				#define CFG_UI_LED5_EN					0	
				// <o> LED5ʹ�õ�GPIO��
					// <i>Ĭ��: 1
					// <0x01=> GPIOA��
					// <0x02=> GPIOB��
					// <0x04=> GPIOC��
					#define CFG_PIN_LED5_PORT			0x02
				// <o> LED5ʹ�õ�GPIO��
					// <i>Ĭ��: 1
					// <0x01=> PIN0
					// <0x02=> PIN1
					// <0x04=> PIN2
					// <0x08=> PIN3
					#define CFG_PIN_LED5_PINNUM			0x04
			// </e>							
		// </h>			
		// <e> PWM0����LEDʹ�ܣ�����LED0/LED1/LED2��
			#define CFG_PWM0_CTRL_EN    		1		
			// <o> PWM0��ʱ�ӷ�Ƶ
				// <i>Ĭ��: 7��Ƶϵ��128��125K��
				// <0=> ��Ƶϵ��1��16M��
				// <1=> ��Ƶϵ��2��8M��
				// <2=> ��Ƶϵ��4��4M��
				// <3=> ��Ƶϵ��8��2M��
				// <4=> ��Ƶϵ��16��1M��
				// <5=> ��Ƶϵ��32��500K��
				// <6=> ��Ƶϵ��64��250K��
				// <7=> ��Ƶϵ��128��125K��
				#define CFG_PWM0_FCLK_SET           7 
			// <o> PWM0�������
				// <i> Ĭ�ϣ�61
				// <i> ���Ƶ��=��Ƶʱ��/�������
				// <0-255>
				#define CFG_PWM0_PERIOD      		255
			// <e> PWM0���Է�תʹ��
				#define CFG_PWM0_NEGATE_EN    		1
			// </e>								
		// </e>			
		// <e> PWM1����LEDʹ�ܣ�����LED3/LED4/LED5��
			#define CFG_PWM1_CTRL_EN    		0		
			// <o> PWM1��ʱ�ӷ�Ƶ
				// <i>Ĭ��: 7��Ƶϵ��128��125K��
				// <0=> ��Ƶϵ��1��16M��
				// <1=> ��Ƶϵ��2��8M��
				// <2=> ��Ƶϵ��4��4M��
				// <3=> ��Ƶϵ��8��2M��
				// <4=> ��Ƶϵ��16��1M��
				// <5=> ��Ƶϵ��32��500K��
				// <6=> ��Ƶϵ��64��250K��
				// <7=> ��Ƶϵ��128��125K��
				#define CFG_PWM1_FCLK_SET           7 
			// <o> PWM1�������
				// <i> Ĭ�ϣ�61
				// <i> ���Ƶ��=��Ƶʱ��/�������
				// <0-255>
				#define CFG_PWM1_PERIOD      		255
			// <e> PWM1���Է�תʹ��(����LEDʹ��)
				#define CFG_PWM1_NEGATE_EN    		0
			// </e>								
		// </e>			
		// <h> ��Ч����		
			// <e> �ϵ����ƣ�POR��
				#define CFG_UI_LED_POR			1
				//	<h>��ɫ
					// <o0.0> LED0 ��
					// <o0.1> LED1 ��
					// <o0.2> LED2 ��
					// <o0.3> LED3 ��
					// <o0.4> LED4 ��		
					// <o0.5> LED5 ��
					#define CFG_UI_LED_COLOR_POR    0x01
				// </h>
				// <o> ���ģʽѡ��
					// <0=>  0 - �޶���
					// <1=>  1 - ����
					// <2=>  2 - Ϩ��
					// <3=>  3 - ����
					// <4=>  4 - ����
					// <5=>  5 - ��˸
					// <6=>  6 - ����
					// <7=>  7 - �ϵ���������
					#define   CFG_UI_LED_TYPE_POR		7
				// <o> ��/���ʱ����LSB=10ms��
					#define   CFG_UI_LED_ONTIME_POR		50
				// <o> ���ƻ��ߺ�������
					#define   CFG_UI_LED_CNT_POR		3
			// </e>
			// <e> �͵縴λ���ƣ�LVR��
				#define CFG_UI_LED_LVR			0
				//	<h>��ɫ
					// <o0.0> LED0 ��
					// <o0.1> LED1 ��
					// <o0.2> LED2 ��
					// <o0.3> LED3 ��
					// <o0.4> LED4 ��		
					// <o0.5> LED5 ��					
					#define CFG_UI_LED_COLOR_LVR    0x07
				// </h>
				// <o> ���ģʽѡ��
					// <0=>  0 - �޶���
					// <1=>  1 - ����
					// <2=>  2 - Ϩ��
					// <3=>  3 - ����
					// <4=>  4 - ����
					// <5=>  5 - ��˸
					// <6=>  6 - ����
					#define   CFG_UI_LED_TYPE_LVR		5
				// <o> ��/���ʱ����LSB=10ms��
					#define   CFG_UI_LED_ONTIME_LVR		25
				// <o> ���ƻ��ߺ�������
					#define   CFG_UI_LED_CNT_LVR		1
			// </e>		
			// <e> USB���루USB_IN��
				#define CFG_UI_LED_USB_IN			1
				//	<h>��ɫ
					// <o0.0> LED0 ��
					// <o0.1> LED1 ��
					// <o0.2> LED2 ��
					// <o0.3> LED3 ��
					// <o0.4> LED4 ��		
					// <o0.5> LED5 ��					
					#define CFG_UI_LED_COLOR_USB_IN    0x07
				// </h>
				// <o> ���ģʽѡ��
					// <0=>  0 - �޶���
					// <1=>  1 - ����
					// <2=>  2 - Ϩ��
					// <3=>  3 - ����
					// <4=>  4 - ����
					// <5=>  5 - ��˸
					// <6=>  6 - ����
					#define   CFG_UI_LED_TYPE_USB_IN		5
				// <o> ��/���ʱ����LSB=10ms��
					#define   CFG_UI_LED_ONTIME_USB_IN		30
				// <o> ���ƻ��ߺ�������
					#define   CFG_UI_LED_CNT_USB_IN			3
			// </e>		
			// <e> USB����У�USB_CHARGING��
				#define CFG_UI_LED_USB_CHARGING			1
				//	<h>��ɫ
					// <o0.0> LED0 ��
					// <o0.1> LED1 ��
					// <o0.2> LED2 ��
					// <o0.3> LED3 ��
					// <o0.4> LED4 ��		
					// <o0.5> LED5 ��					
					#define CFG_UI_LED_COLOR_USB_CHARGING    0x07
				// </h>
				// <o> ���ģʽѡ��
					// <0=>  0 - �޶���
					// <1=>  1 - ����
					// <2=>  2 - Ϩ��
					// <3=>  3 - ����
					// <4=>  4 - ����
					// <5=>  5 - ��˸
					// <6=>  6 - ����
					#define   CFG_UI_LED_TYPE_USB_CHARGING		1
				// <o> ��/���ʱ����LSB=10ms��
					#define   CFG_UI_LED_ONTIME_USB_CHARGING	30
				// <o> ���ƻ��ߺ�������
					#define   CFG_UI_LED_CNT_USB_CHARGING		1
			// </e>				
			// <e> USB���䣨USB_FULL��
				#define CFG_UI_LED_USB_FULL			1
				//	<h>��ɫ
					// <o0.0> LED0 ��
					// <o0.1> LED1 ��
					// <o0.2> LED2 ��
					// <o0.3> LED3 ��
					// <o0.4> LED4 ��		
					// <o0.5> LED5 ��					
					#define CFG_UI_LED_COLOR_USB_FULL    0x07
				// </h>
				// <o> ���ģʽѡ��
					// <0=>  0 - �޶���
					// <1=>  1 - ����
					// <2=>  2 - Ϩ��
					// <3=>  3 - ����
					// <4=>  4 - ����
					// <5=>  5 - ��˸
					// <6=>  6 - ����
					#define   CFG_UI_LED_TYPE_USB_FULL		5
				// <o> ��/���ʱ����LSB=10ms��
					#define   CFG_UI_LED_ONTIME_USB_FULL	25
				// <o> ���ƻ��ߺ�������
					#define   CFG_UI_LED_CNT_USB_FULL		20
			// </e>			
			// <e> USB�γ���USB_OUT��
				#define CFG_UI_LED_USB_OUT			1
				//	<h>��ɫ
					// <o0.0> LED0 ��
					// <o0.1> LED1 ��
					// <o0.2> LED2 ��
					// <o0.3> LED3 ��
					// <o0.4> LED4 ��		
					// <o0.5> LED5 ��					
					#define CFG_UI_LED_COLOR_USB_OUT    0x07
				// </h>
				// <o> ���ģʽѡ��
					// <0=>  0 - �޶���
					// <1=>  1 - ����
					// <2=>  2 - Ϩ��
					// <3=>  3 - ����
					// <4=>  4 - ����
					// <5=>  5 - ��˸
					// <6=>  6 - ����
					#define   CFG_UI_LED_TYPE_USB_OUT		5
				// <o> ��/���ʱ����LSB=10ms��
					#define   CFG_UI_LED_ONTIME_USB_OUT		30
				// <o> ���ƻ��ߺ�������
					#define   CFG_UI_LED_CNT_USB_OUT		3
			// </e>
				// <e> USB��ѹ��USB_OVP��
				#define CFG_UI_LED_USB_OVP			1
				//	<h>��ɫ
					// <o0.0> LED0 ��
					// <o0.1> LED1 ��
					// <o0.2> LED2 ��
					// <o0.3> LED3 ��
					// <o0.4> LED4 ��		
					// <o0.5> LED5 ��					
					#define CFG_UI_LED_COLOR_USB_OVP    0x07
				// </h>
				// <o> ���ģʽѡ��
					// <0=>  0 - �޶���
					// <1=>  1 - ����
					// <2=>  2 - Ϩ��
					// <3=>  3 - ����
					// <4=>  4 - ����
					// <5=>  5 - ��˸
					// <6=>  6 - ����
					#define   CFG_UI_LED_TYPE_USB_OVP		2
				// <o> ��/���ʱ����LSB=10ms��
					#define   CFG_UI_LED_ONTIME_USB_OVP		0
				// <o> ���ƻ��ߺ�������
					#define   CFG_UI_LED_CNT_USB_OVP		0
			// </e>					
			// <e> ��ʼ�ŵ磨FIRE_START��
				#define CFG_UI_LED_FIRE_START			1
				//	<h>��ɫ
					// <o0.0> LED0 ��
					// <o0.1> LED1 ��
					// <o0.2> LED2 ��
					// <o0.3> LED3 ��
					// <o0.4> LED4 ��		
					// <o0.5> LED5 ��					
					#define CFG_UI_LED_COLOR_FIRE_START    0x07
				// </h>
				// <o> ���ģʽѡ��
					// <0=>  0 - �޶���
					// <1=>  1 - ����
					// <2=>  2 - Ϩ��
					// <3=>  3 - ����
					// <4=>  4 - ����
					// <5=>  5 - ��˸
					// <6=>  6 - ����
					#define   CFG_UI_LED_TYPE_FIRE_START		3
				// <o> ��/���ʱ����LSB=10ms��
					#define   CFG_UI_LED_ONTIME_FIRE_START		100
				// <o> ���ƻ��ߺ�������
					#define   CFG_UI_LED_CNT_FIRE_START			1
			// </e>			
			// <e> �����ŵ磨FIRE_STOP��
				#define CFG_UI_LED_FIRE_STOP			1
				//	<h>��ɫ
					// <o0.0> LED0 ��
					// <o0.1> LED1 ��
					// <o0.2> LED2 ��
					// <o0.3> LED3 ��
					// <o0.4> LED4 ��		
					// <o0.5> LED5 ��					
					#define CFG_UI_LED_COLOR_FIRE_STOP    0x07
				// </h>
				// <o> ���ģʽѡ��
					// <0=>  0 - �޶���
					// <1=>  1 - ����
					// <2=>  2 - Ϩ��
					// <3=>  3 - ����
					// <4=>  4 - ����
					// <5=>  5 - ��˸
					// <6=>  6 - ����
					#define   CFG_UI_LED_TYPE_FIRE_STOP		4
				// <o> ��/���ʱ����LSB=10ms��
					#define   CFG_UI_LED_ONTIME_FIRE_STOP	100
				// <o> ���ƻ��ߺ�������
					#define   CFG_UI_LED_CNT_FIRE_STOP		1
			// </e>	
			// <e> ���̳�ʱ��FIRE_TIMEOUT��
				#define CFG_UI_LED_FIRE_TIMEOUT			1
				//	<h>��ɫ
					// <o0.0> LED0 ��
					// <o0.1> LED1 ��
					// <o0.2> LED2 ��
					// <o0.3> LED3 ��
					// <o0.4> LED4 ��		
					// <o0.5> LED5 ��					
					#define CFG_UI_LED_COLOR_FIRE_TIMEOUT    0x07
				// </h>
				// <o> ���ģʽѡ��
					// <0=>  0 - �޶���
					// <1=>  1 - ����
					// <2=>  2 - Ϩ��
					// <3=>  3 - ����
					// <4=>  4 - ����
					// <5=>  5 - ��˸
					// <6=>  6 - ����
					#define   CFG_UI_LED_TYPE_FIRE_TIMEOUT		5
				// <o> ��/���ʱ����LSB=10ms��
					#define   CFG_UI_LED_ONTIME_FIRE_TIMEOUT	25
				// <o> ���ƻ��ߺ�������
					#define   CFG_UI_LED_CNT_FIRE_TIMEOUT		3
			// </e>
			// <e> Ԥ�ȣ�PREFIRE��
				#define CFG_UI_LED_FIRE_PREFIRE			1
				//	<h>��ɫ
					// <o0.0> LED0 ��
					// <o0.1> LED1 ��
					// <o0.2> LED2 ��
					// <o0.3> LED3 ��
					// <o0.4> LED4 ��		
					// <o0.5> LED5 ��					
					#define CFG_UI_LED_COLOR_FIRE_PREFIRE    0x07
				// </h>
				// <o> ���ģʽѡ��
					// <0=>  0 - �޶���
					// <1=>  1 - ����
					// <2=>  2 - Ϩ��
					// <3=>  3 - ����
					// <4=>  4 - ����
					// <5=>  5 - ��˸
					// <6=>  6 - ����
					#define   CFG_UI_LED_TYPE_FIRE_PREFIRE		6
				// <o> ��/���ʱ����LSB=10ms��
					#define   CFG_UI_LED_ONTIME_FIRE_PREFIRE	100
				// <o> ���ƻ��ߺ�������
					#define   CFG_UI_LED_CNT_FIRE_PREFIRE		1
			// </e>		
			// <e> Ԥ�ȳ�ʱ��PREFIRE_OT��
				#define CFG_UI_LED_FIRE_PREFIREOT			1
				//	<h>��ɫ
					// <o0.0> LED0 ��
					// <o0.1> LED1 ��
					// <o0.2> LED2 ��
					// <o0.3> LED3 ��
					// <o0.4> LED4 ��		
					// <o0.5> LED5 ��					
					#define CFG_UI_LED_COLOR_FIRE_PREFIREOT    0x07
				// </h>
				// <o> ���ģʽѡ��
					// <0=>  0 - �޶���
					// <1=>  1 - ����
					// <2=>  2 - Ϩ��
					// <3=>  3 - ����
					// <4=>  4 - ����
					// <5=>  5 - ��˸
					// <6=>  6 - ����
					#define   CFG_UI_LED_TYPE_FIRE_PREFIREOT		2
				// <o> ��/���ʱ����LSB=10ms��
					#define   CFG_UI_LED_ONTIME_FIRE_PREFIREOT	0
				// <o> ���ƻ��ߺ�������
					#define   CFG_UI_LED_CNT_FIRE_PREFIREOT		0
			// </e>			
			// <e> ���ؽ��루RL_IN��
				#define CFG_UI_LED_RL_IN			0
				//	<h>��ɫ
					// <o0.0> LED0 ��
					// <o0.1> LED1 ��
					// <o0.2> LED2 ��
					// <o0.3> LED3 ��
					// <o0.4> LED4 ��		
					// <o0.5> LED5 ��					
					#define CFG_UI_LED_COLOR_RL_IN    0x07
				// </h>
				// <o> ���ģʽѡ��
					// <0=>  0 - �޶���
					// <1=>  1 - ����
					// <2=>  2 - Ϩ��
					// <3=>  3 - ����
					// <4=>  4 - ����
					// <5=>  5 - ��˸
					// <6=>  6 - ����
					#define   CFG_UI_LED_TYPE_RL_IN		5
				// <o> ��/���ʱ����LSB=10ms��
					#define   CFG_UI_LED_ONTIME_RL_IN	25
				// <o> ���ƻ��ߺ�������
					#define   CFG_UI_LED_CNT_RL_IN		1
			// </e>	
			// <e> ���ذγ���RL_OUT��
				#define CFG_UI_LED_RL_OUT			0
				//	<h>��ɫ
					// <o0.0> LED0 ��
					// <o0.1> LED1 ��
					// <o0.2> LED2 ��
					// <o0.3> LED3 ��
					// <o0.4> LED4 ��		
					// <o0.5> LED5 ��					
					#define CFG_UI_LED_COLOR_RL_OUT    0x07
				// </h>
				// <o> ���ģʽѡ��
					// <0=>  0 - �޶���
					// <1=>  1 - ����
					// <2=>  2 - Ϩ��
					// <3=>  3 - ����
					// <4=>  4 - ����
					// <5=>  5 - ��˸
					// <6=>  6 - ����
					#define   CFG_UI_LED_TYPE_RL_OUT		5
				// <o> ��/���ʱ����LSB=10ms��
					#define   CFG_UI_LED_ONTIME_RL_OUT	25
				// <o> ���ƻ��ߺ�������
					#define   CFG_UI_LED_CNT_RL_OUT		1
			// </e>			
			// <e> ���ض�·��RL_SHORT��
				#define CFG_UI_LED_RL_SHORT			1
				//	<h>��ɫ
					// <o0.0> LED0 ��
					// <o0.1> LED1 ��
					// <o0.2> LED2 ��
					// <o0.3> LED3 ��
					// <o0.4> LED4 ��		
					// <o0.5> LED5 ��					
					#define CFG_UI_LED_COLOR_RL_SHORT    0x07
				// </h>
				// <o> ���ģʽѡ��
					// <0=>  0 - �޶���
					// <1=>  1 - ����
					// <2=>  2 - Ϩ��
					// <3=>  3 - ����
					// <4=>  4 - ����
					// <5=>  5 - ��˸
					// <6=>  6 - ����
					#define   CFG_UI_LED_TYPE_RL_SHORT		1
				// <o> ��/���ʱ����LSB=10ms��
					#define   CFG_UI_LED_ONTIME_RL_SHORT	200
				// <o> ���ƻ��ߺ�������
					#define   CFG_UI_LED_CNT_RL_SHORT		1
			// </e>	
			// <e> ���ص��裨RL_LOW��
				#define CFG_UI_LED_RL_LOW			1
				//	<h>��ɫ
					// <o0.0> LED0 ��
					// <o0.1> LED1 ��
					// <o0.2> LED2 ��
					// <o0.3> LED3 ��
					// <o0.4> LED4 ��		
					// <o0.5> LED5 ��					
					#define CFG_UI_LED_COLOR_RL_LOW    0x07
				// </h>
				// <o> ���ģʽѡ��
					// <0=>  0 - �޶���
					// <1=>  1 - ����
					// <2=>  2 - Ϩ��
					// <3=>  3 - ����
					// <4=>  4 - ����
					// <5=>  5 - ��˸
					// <6=>  6 - ����
					#define   CFG_UI_LED_TYPE_RL_LOW		1
				// <o> ��/���ʱ����LSB=10ms��
					#define   CFG_UI_LED_ONTIME_RL_LOW	200
				// <o> ���ƻ��ߺ�������
					#define   CFG_UI_LED_CNT_RL_LOW		1
			// </e>			
			// <e> ���ؿ�·��RL_OPEN��
				#define CFG_UI_LED_RL_OPEN			0
				//	<h>��ɫ
					// <o0.0> LED0 ��
					// <o0.1> LED1 ��
					// <o0.2> LED2 ��
					// <o0.3> LED3 ��
					// <o0.4> LED4 ��		
					// <o0.5> LED5 ��					
					#define CFG_UI_LED_COLOR_RL_OPEN    0x07
				// </h>
				// <o> ���ģʽѡ��
					// <0=>  0 - �޶���
					// <1=>  1 - ����
					// <2=>  2 - Ϩ��
					// <3=>  3 - ����
					// <4=>  4 - ����
					// <5=>  5 - ��˸
					// <6=>  6 - ����
					#define   CFG_UI_LED_TYPE_RL_OPEN		5
				// <o> ��/���ʱ����LSB=10ms��
					#define   CFG_UI_LED_ONTIME_RL_OPEN	30
				// <o> ���ƻ��ߺ�������
					#define   CFG_UI_LED_CNT_RL_OPEN		4
			// </e>			
			// <e> ���ظ��գ�RL_DRY��
				#define CFG_UI_LED_RL_DRY			0
				//	<h>��ɫ
					// <o0.0> LED0 ��
					// <o0.1> LED1 ��
					// <o0.2> LED2 ��
					// <o0.3> LED3 ��
					// <o0.4> LED4 ��		
					// <o0.5> LED5 ��					
					#define CFG_UI_LED_COLOR_RL_DRY    0x07
				// </h>
				// <o> ���ģʽѡ��
					// <0=>  0 - �޶���
					// <1=>  1 - ����
					// <2=>  2 - Ϩ��
					// <3=>  3 - ����
					// <4=>  4 - ����
					// <5=>  5 - ��˸
					// <6=>  6 - ����
					#define   CFG_UI_LED_TYPE_RL_DRY		5
				// <o> ��/���ʱ����LSB=10ms��
					#define   CFG_UI_LED_ONTIME_RL_DRY	30
				// <o> ���ƻ��ߺ�������
					#define   CFG_UI_LED_CNT_RL_DRY		5
			// </e>			
			// <e> ����ͯ����CHILD_LOCK��
				#define CFG_UI_LED_CHILD_LOCK			1
				//	<h>��ɫ
					// <o0.0> LED0 ��
					// <o0.1> LED1 ��
					// <o0.2> LED2 ��
					// <o0.3> LED3 ��
					// <o0.4> LED4 ��		
					// <o0.5> LED5 ��					
					#define CFG_UI_LED_COLOR_CHILD_LOCK    0x07
				// </h>
				// <o> ���ģʽѡ��
					// <0=>  0 - �޶���
					// <1=>  1 - ����
					// <2=>  2 - Ϩ��
					// <3=>  3 - ����
					// <4=>  4 - ����
					// <5=>  5 - ��˸
					// <6=>  6 - ����
					#define   CFG_UI_LED_TYPE_CHILD_LOCK		5
				// <o> ��/���ʱ����LSB=10ms��
					#define   CFG_UI_LED_ONTIME_CHILD_LOCK	50
				// <o> ���ƻ��ߺ�������
					#define   CFG_UI_LED_CNT_CHILD_LOCK		5
			// </e>			
			// <e> ͯ��������CHILD_UNLOCK��
				#define CFG_UI_LED_CHILD_UNLOCK			1
				//	<h>��ɫ
					// <o0.0> LED0 ��
					// <o0.1> LED1 ��
					// <o0.2> LED2 ��
					// <o0.3> LED3 ��
					// <o0.4> LED4 ��		
					// <o0.5> LED5 ��					
					#define CFG_UI_LED_COLOR_CHILD_UNLOCK    0x07
				// </h>
				// <o> ���ģʽѡ��
					// <0=>  0 - �޶���
					// <1=>  1 - ����
					// <2=>  2 - Ϩ��
					// <3=>  3 - ����
					// <4=>  4 - ����
					// <5=>  5 - ��˸
					// <6=>  6 - ����
					#define   CFG_UI_LED_TYPE_CHILD_UNLOCK		5
				// <o> ��/���ʱ����LSB=10ms��
					#define   CFG_UI_LED_ONTIME_CHILD_UNLOCK	50
				// <o> ���ƻ��ߺ�������
					#define   CFG_UI_LED_CNT_CHILD_UNLOCK		5
			// </e>		
			// <e> ��ص�ѹ��BAT_LOW��
				#define CFG_UI_LED_BAT_LOW			1
				//	<h>��ɫ
					// <o0.0> LED0 ��
					// <o0.1> LED1 ��
					// <o0.2> LED2 ��
					// <o0.3> LED3 ��
					// <o0.4> LED4 ��		
					// <o0.5> LED5 ��					
					#define CFG_UI_LED_COLOR_BAT_LOW    0x07
				// </h>
				// <o> ���ģʽѡ��
					// <0=>  0 - �޶���
					// <1=>  1 - ����
					// <2=>  2 - Ϩ��
					// <3=>  3 - ����
					// <4=>  4 - ����
					// <5=>  5 - ��˸
					// <6=>  6 - ����
					#define   CFG_UI_LED_TYPE_BAT_LOW		5
				// <o> ��/���ʱ����LSB=10ms��
					#define   CFG_UI_LED_ONTIME_BAT_LOW	25
				// <o> ���ƻ��ߺ�������
					#define   CFG_UI_LED_CNT_BAT_LOW		10
			// </e>			
			// <e> ϵͳ������SYS_LOCK��
				#define CFG_UI_LED_SYS_LOCK			0
				//	<h>��ɫ
					// <o0.0> LED0 ��
					// <o0.1> LED1 ��
					// <o0.2> LED2 ��
					// <o0.3> LED3 ��
					// <o0.4> LED4 ��		
					// <o0.5> LED5 ��					
					#define CFG_UI_LED_COLOR_SYS_LOCK    0x07
				// </h>
				// <o> ���ģʽѡ��
					// <0=>  0 - �޶���
					// <1=>  1 - ����
					// <2=>  2 - Ϩ��
					// <3=>  3 - ����
					// <4=>  4 - ����
					// <5=>  5 - ��˸
					// <6=>  6 - ����
					#define   CFG_UI_LED_TYPE_SYS_LOCK		5
				// <o> ��/���ʱ����LSB=10ms��
					#define   CFG_UI_LED_ONTIME_SYS_LOCK	50
				// <o> ���ƻ��ߺ�������
					#define   CFG_UI_LED_CNT_SYS_LOCK		3
			// </e>			
			// <e> ϵͳ������SYS_UNLOCK��
				#define CFG_UI_LED_SYS_UNLOCK			0
				//	<h>��ɫ
					// <o0.0> LED0 ��
					// <o0.1> LED1 ��
					// <o0.2> LED2 ��
					// <o0.3> LED3 ��
					// <o0.4> LED4 ��		
					// <o0.5> LED5 ��					
					#define CFG_UI_LED_COLOR_SYS_UNLOCK    0x07
				// </h>
				// <o> ���ģʽѡ��
					// <0=>  0 - �޶���
					// <1=>  1 - ����
					// <2=>  2 - Ϩ��
					// <3=>  3 - ����
					// <4=>  4 - ����
					// <5=>  5 - ��˸
					// <6=>  6 - ����
					#define   CFG_UI_LED_TYPE_SYS_UNLOCK		5
				// <o> ��/���ʱ����LSB=10ms��
					#define   CFG_UI_LED_ONTIME_SYS_UNLOCK	50
				// <o> ���ƻ��ߺ�������
					#define   CFG_UI_LED_CNT_SYS_UNLOCK		3
			// </e>		
			// <e> оƬ���£�CHIP_OTP��
				#define CFG_UI_LED_CHIP_OTP			0
				//	<h>��ɫ
					// <o0.0> LED0 ��
					// <o0.1> LED1 ��
					// <o0.2> LED2 ��
					// <o0.3> LED3 ��
					// <o0.4> LED4 ��		
					// <o0.5> LED5 ��					
					#define CFG_UI_LED_COLOR_CHIP_OTP    0x07
				// </h>
				// <o> ���ģʽѡ��
					// <0=>  0 - �޶���
					// <1=>  1 - ����
					// <2=>  2 - Ϩ��
					// <3=>  3 - ����
					// <4=>  4 - ����
					// <5=>  5 - ��˸
					// <6=>  6 - ����
					#define   CFG_UI_LED_TYPE_CHIP_OTP		5
				// <o> ��/���ʱ����LSB=10ms��
					#define   CFG_UI_LED_ONTIME_CHIP_OTP	25
				// <o> ���ƻ��ߺ�������
					#define   CFG_UI_LED_CNT_CHIP_OTP		5
			// </e>
			// <e> �����ƹ⣨CHANGE_SW��
				#define CFG_UI_LED_CHANGE_SW			1
				//	<h>��ɫ
					// <o0.0> LED0 ��
					// <o0.1> LED1 ��
					// <o0.2> LED2 ��
					// <o0.3> LED3 ��
					// <o0.4> LED4 ��		
					// <o0.5> LED5 ��					
					#define CFG_UI_LED_COLOR_CHANGE_SW    0x07
				// </h>
				// <o> ���ģʽѡ��
					// <0=>  0 - �޶���
					// <1=>  1 - ����
					// <2=>  2 - Ϩ��
					// <3=>  3 - ����
					// <4=>  4 - ����
					// <5=>  5 - ��˸
					// <6=>  6 - ����
					#define   CFG_UI_LED_TYPE_CHANGE_SW		5
				// <o> ��/���ʱ����LSB=10ms��
					#define   CFG_UI_LED_ONTIME_CHANGE_SW	25
				// <o> ���ƻ��ߺ�������
					#define   CFG_UI_LED_CNT_CHANGE_SW		3
			// </e>			
		// </h>	
	// </e>

	// <e> ���������ܣ���LED���ܶ�ѡһ��
		#define CFG_UI_SCREEN_EN				0		
		// <h> �����ܽ����ã�����ʵ�ʶ�������˳��ʹ�ܹܽţ�
			// <e> COM1      
				#define CFG_UI_COM1_EN					1	
				// <o> COM1ʹ�õ�GPIO��
					// <i>Ĭ��: 1
					// <0x01=> GPIOA��
					// <0x02=> GPIOB��
					// <0x04=> GPIOC��
					#define CFG_PIN_COM1_PORT			0x02
				// <o> COM1ʹ�õ�GPIO��
					// <i>Ĭ��: 1
					// <0x01=> PIN0
					// <0x02=> PIN1
					// <0x04=> PIN2
					// <0x08=> PIN3
					#define CFG_PIN_COM1_PINNUM			0x08
			// </e>	
			// <e> COM2      
				#define CFG_UI_COM2_EN					1	
				// <o> COM2ʹ�õ�GPIO��
					// <i>Ĭ��: 1
					// <0x01=> GPIOA��
					// <0x02=> GPIOB��
					// <0x04=> GPIOC��
					#define CFG_PIN_COM2_PORT			0x02
				// <o> COM2ʹ�õ�GPIO��
					// <i>Ĭ��: 1
					// <0x01=> PIN0
					// <0x02=> PIN1
					// <0x04=> PIN2
					// <0x08=> PIN3
					#define CFG_PIN_COM2_PINNUM			0x04
			// </e>	
			// <e> COM3      
				#define CFG_UI_COM3_EN					1	
				// <o> COM3ʹ�õ�GPIO��
					// <i>Ĭ��: 1
					// <0x01=> GPIOA��
					// <0x02=> GPIOB��
					// <0x04=> GPIOC��
					#define CFG_PIN_COM3_PORT			0x01
				// <o> COM3ʹ�õ�GPIO��
					// <i>Ĭ��: 1
					// <0x01=> PIN0
					// <0x02=> PIN1
					// <0x04=> PIN2
					// <0x08=> PIN3
					#define CFG_PIN_COM3_PINNUM			0x08
			// </e>	
			// <e> COM4      
				#define CFG_UI_COM4_EN					1	
				// <o> COM4ʹ�õ�GPIO��
					// <i>Ĭ��: 1
					// <0x01=> GPIOA��
					// <0x02=> GPIOB��
					// <0x04=> GPIOC��
					#define CFG_PIN_COM4_PORT			0x01
				// <o> COM4ʹ�õ�GPIO��
					// <i>Ĭ��: 1
					// <0x01=> PIN0
					// <0x02=> PIN1
					// <0x04=> PIN2
					// <0x08=> PIN3
					#define CFG_PIN_COM4_PINNUM			0x04
			// </e>	
			// <e> COM5      
				#define CFG_UI_COM5_EN					1	
				// <o> COM5ʹ�õ�GPIO��
					// <i>Ĭ��: 1
					// <0x01=> GPIOA��
					// <0x02=> GPIOB��
					// <0x04=> GPIOC��
					#define CFG_PIN_COM5_PORT			0x01
				// <o> COM5ʹ�õ�GPIO��
					// <i>Ĭ��: 1
					// <0x01=> PIN0
					// <0x02=> PIN1
					// <0x04=> PIN2
					// <0x08=> PIN3
					#define CFG_PIN_COM5_PINNUM			0x02
			// </e>	
			// <e> COM6      
				#define CFG_UI_COM6_EN					0	
				// <o> COM6ʹ�õ�GPIO��
					// <i>Ĭ��: 1
					// <0x01=> GPIOA��
					// <0x02=> GPIOB��
					// <0x04=> GPIOC��
					#define CFG_PIN_COM6_PORT			0x02
				// <o> COM6ʹ�õ�GPIO��
					// <i>Ĭ��: 1
					// <0x01=> PIN0
					// <0x02=> PIN1
					// <0x04=> PIN2
					// <0x08=> PIN3
					#define CFG_PIN_COM6_PINNUM			0x02
			// </e>	
			// <e> COM7      
				#define CFG_UI_COM7_EN					0	
				// <o> COM7ʹ�õ�GPIO��
					// <i>Ĭ��: 1
					// <0x01=> GPIOA��
					// <0x02=> GPIOB��
					// <0x04=> GPIOC��
					#define CFG_PIN_COM7_PORT			0x02
				// <o> COM7ʹ�õ�GPIO��
					// <i>Ĭ��: 1
					// <0x01=> PIN0
					// <0x02=> PIN1
					// <0x04=> PIN2
					// <0x08=> PIN3
					#define CFG_PIN_COM7_PINNUM			0x04
			// </e>	
			// <e> COM8      
				#define CFG_UI_COM8_EN					0	
				// <o> COM8ʹ�õ�GPIO��
					// <i>Ĭ��: 1
					// <0x01=> GPIOA��
					// <0x02=> GPIOB��
					// <0x04=> GPIOC��
					#define CFG_PIN_COM8_PORT			0x02
				// <o> COM8ʹ�õ�GPIO��
					// <i>Ĭ��: 1
					// <0x01=> PIN0
					// <0x02=> PIN1
					// <0x04=> PIN2
					// <0x08=> PIN3
					#define CFG_PIN_COM8_PINNUM			0x08
			// </e>	
			// <e> COM9      
				#define CFG_UI_COM9_EN					0	
				// <o> COM9ʹ�õ�GPIO��
					// <i>Ĭ��: 1
					// <0x01=> GPIOA��
					// <0x02=> GPIOB��
					// <0x04=> GPIOC��
					#define CFG_PIN_COM9_PORT			0x04
				// <o> COM9ʹ�õ�GPIO��
					// <i>Ĭ��: 1
					// <0x01=> PIN0
					// <0x02=> PIN1
					// <0x04=> PIN2
					// <0x08=> PIN3
					#define CFG_PIN_COM9_PINNUM			0x02
			// </e>			
		// </h>	
    
    // <e> ʹ����Ļ������Ч
        #define CFG_UI_SCREEN_SOFT_PWM_BREATH_EN  0
    // </e>
    
		// <h> ��Ч����		
			// <e> �ϵ����ƣ�POR��
				#define CFG_UI_SCREEN_POR			1
				// <o> ���ģʽѡ��
					// <0=>  0 - �޶���
					// <1=>  1 - Ϩ��
					// <2=>  2 - ����
					// <3=>  3 - ��˸
					// <4=>  4 - ά�ֵ�ǰ״̬
					// <5=>  5 - �����
					#define   CFG_UI_SCREEN_TYPE_POR		3
				// <o> ��/���ʱ����LSB=10ms��
					#define   CFG_UI_SCREEN_ONTIME_POR		25
				// <o> ���ƻ��ߺ�������
					#define   CFG_UI_SCREEN_CNT_POR		1
				// <o> ���ƺ�״̬
					// <0=>  0 - �����Ϩ��
					// <1=>  1 - ������
					// <2=>  2 - һֱ��
					#define   CFG_UI_SCREEN_END_STATE_POR		0				
			// </e>
			// <e> �͵縴λ���ƣ�LVR��
				#define CFG_UI_SCREEN_LVR			1
				// <o> ���ģʽѡ��
					// <0=>  0 - �޶���
					// <1=>  1 - Ϩ��
					// <2=>  2 - ����
					// <3=>  3 - ��˸
					// <4=>  4 - ά�ֵ�ǰ״̬
					// <5=>  5 - �����
					#define   CFG_UI_SCREEN_TYPE_LVR		3
				// <o> ��/���ʱ����LSB=10ms��
					#define   CFG_UI_SCREEN_ONTIME_LVR		25
				// <o> ���ƻ��ߺ�������
					#define   CFG_UI_SCREEN_CNT_LVR		2
				// <o> ���ƺ�״̬
					// <0=>  0 - �����Ϩ��
					// <1=>  1 - ������
					// <2=>  2 - һֱ��
					#define   CFG_UI_SCREEN_END_STATE_LVR		0				
			// </e>		
			// <e> USB���루USB_IN��
				#define CFG_UI_SCREEN_USB_IN			1
				// <o> ���ģʽѡ��
					// <0=>  0 - �޶���
					// <1=>  1 - Ϩ��
					// <2=>  2 - ����
					// <3=>  3 - ��˸
					// <4=>  4 - ά�ֵ�ǰ״̬
					// <5=>  5 - �����
					#define   CFG_UI_SCREEN_TYPE_USB_IN		3
				// <o> ��/���ʱ����LSB=10ms��
					#define   CFG_UI_SCREEN_ONTIME_USB_IN		50
				// <o> ���ƻ��ߺ�������
					#define   CFG_UI_SCREEN_CNT_USB_IN			2
				// <o> ���ƺ�״̬
					// <0=>  0 - �����Ϩ��
					// <1=>  1 - ������
					// <2=>  2 - һֱ��
					#define   CFG_UI_SCREEN_END_STATE_USB_IN		2				
			// </e>		
			// <e> USB����У�USB_CHARGING��
				#define CFG_UI_SCREEN_USB_CHARGING			1
				// <o> ���ģʽѡ��
					// <0=>  0 - �޶���
					// <1=>  1 - Ϩ��
					// <2=>  2 - ����
					// <3=>  3 - ��˸
					// <4=>  4 - ά�ֵ�ǰ״̬
					// <5=>  5 - �����
					#define   CFG_UI_SCREEN_TYPE_USB_CHARGING		3
				// <o> ��/���ʱ����LSB=10ms��
					#define   CFG_UI_SCREEN_ONTIME_USB_CHARGING	50
				// <o> ���ƻ��ߺ�������
					#define   CFG_UI_SCREEN_CNT_USB_CHARGING		2
				// <o> ���ƺ�״̬
					// <0=>  0 - �����Ϩ��
					// <1=>  1 - ������
					// <2=>  2 - һֱ��
					#define   CFG_UI_SCREEN_END_STATE_USB_CHARGING		2					
			// </e>				
			// <e> USB���䣨USB_FULL��
				#define CFG_UI_SCREEN_USB_FULL			1
				// <o> ���ģʽѡ��
					// <0=>  0 - �޶���
					// <1=>  1 - Ϩ��
					// <2=>  2 - ����
					// <3=>  3 - ��˸
					// <4=>  4 - ά�ֵ�ǰ״̬
					// <5=>  5 - �����
					#define   CFG_UI_SCREEN_TYPE_USB_FULL		1
				// <o> ��/���ʱ����LSB=10ms��
					#define   CFG_UI_SCREEN_ONTIME_USB_FULL	0
				// <o> ���ƻ��ߺ�������
					#define   CFG_UI_SCREEN_CNT_USB_FULL		0
				// <o> ���ƺ�״̬
					// <0=>  0 - �����Ϩ��
					// <1=>  1 - ������
					// <2=>  2 - һֱ��
					#define   CFG_UI_SCREEN_END_STATE_USB_FULL		0	
			// </e>			
			// <e> USB�γ���USB_OUT��
				#define CFG_UI_SCREEN_USB_OUT			1
				// <o> ���ģʽѡ��
					// <0=>  0 - �޶���
					// <1=>  1 - Ϩ��
					// <2=>  2 - ����
					// <3=>  3 - ��˸
					// <4=>  4 - ά�ֵ�ǰ״̬
					// <5=>  5 - �����
					#define   CFG_UI_SCREEN_TYPE_USB_OUT		3
				// <o> ��/���ʱ����LSB=10ms��
					#define   CFG_UI_SCREEN_ONTIME_USB_OUT	25
				// <o> ���ƻ��ߺ�������
					#define   CFG_UI_SCREEN_CNT_USB_OUT		1
				// <o> ���ƺ�״̬
					// <0=>  0 - �����Ϩ��
					// <1=>  1 - ������
					// <2=>  2 - һֱ��
					#define   CFG_UI_SCREEN_END_STATE_USB_OUT		0	
			// </e>			
			// <e> ��ʼ�ŵ磨FIRE_START��
			#define CFG_UI_SCREEN_FIRE_START			1
				// <o> ���ģʽѡ��
					// <0=>  0 - �޶���
					// <1=>  1 - Ϩ��
					// <2=>  2 - ����
					// <3=>  3 - ��˸				
					// <4=>  4 - ά�ֵ�ǰ״̬
					// <5=>  5 - �����
					#define   CFG_UI_SCREEN_TYPE_FIRE_START		5
				// <o> ��/���ʱ����LSB=10ms��
					#define   CFG_UI_SCREEN_ONTIME_FIRE_START	10
				// <o> ���ƻ��ߺ�������
					#define   CFG_UI_SCREEN_CNT_FIRE_START		1
				// <o> ���ƺ�״̬
					// <0=>  0 - �����Ϩ��
					// <1=>  1 - ������
					// <2=>  2 - һֱ��
					#define   CFG_UI_SCREEN_END_STATE_FIRE_START		2
			// </e>			
			// <e> �����ŵ磨FIRE_STOP��
			#define CFG_UI_SCREEN_FIRE_STOP			1
				// <o> ���ģʽѡ��
					// <0=>  0 - �޶���
					// <1=>  1 - Ϩ��
					// <2=>  2 - ����
					// <3=>  3 - ��˸
					// <4=>  4 - ά�ֵ�ǰ״̬
					// <5=>  5 - �����
					#define   CFG_UI_SCREEN_TYPE_FIRE_STOP		4
				// <o> ��/���ʱ����LSB=10ms��
					#define   CFG_UI_SCREEN_ONTIME_FIRE_STOP	300
				// <o> ���ƻ��ߺ�������
					#define   CFG_UI_SCREEN_CNT_FIRE_STOP		1
				// <o> ���ƺ�״̬
					// <0=>  0 - �����Ϩ��
					// <1=>  1 - ������
					// <2=>  2 - һֱ��
					#define   CFG_UI_SCREEN_END_STATE_FIRE_STOP		0
			// </e>	
			// <e> ���̳�ʱ��FIRE_TIMEOUT��
			#define CFG_UI_SCREEN_FIRE_TIMEOUT			1
				// <o> ���ģʽѡ��
					// <0=>  0 - �޶���
					// <1=>  1 - Ϩ��
					// <2=>  2 - ����
					// <3=>  3 - ��˸
					// <4=>  4 - ά�ֵ�ǰ״̬
					// <5=>  5 - �����
					#define   CFG_UI_SCREEN_TYPE_FIRE_TIMEOUT		3
				// <o> ��/���ʱ����LSB=10ms��
					#define   CFG_UI_SCREEN_ONTIME_FIRE_TIMEOUT	40
				// <o> ���ƻ��ߺ�������
					#define   CFG_UI_SCREEN_CNT_FIRE_TIMEOUT		5
				// <o> ���ƺ�״̬
					// <0=>  0 - �����Ϩ��
					// <1=>  1 - ������
					// <2=>  2 - һֱ��
					#define   CFG_UI_SCREEN_END_STATE_FIRE_TIMEOUT		0
			// </e>					
			// <e> ���ؽ��루RL_IN��
			#define CFG_UI_SCREEN_RL_IN			1
				// <o> ���ģʽѡ��
					// <0=>  0 - �޶���
					// <1=>  1 - Ϩ��
					// <2=>  2 - ����
					// <3=>  3 - ��˸
					// <4=>  4 - ά�ֵ�ǰ״̬
					// <5=>  5 - �����
					#define   CFG_UI_SCREEN_TYPE_RL_IN		3
				// <o> ��/���ʱ����LSB=10ms��
					#define   CFG_UI_SCREEN_ONTIME_RL_IN	20
				// <o> ���ƻ��ߺ�������
					#define   CFG_UI_SCREEN_CNT_RL_IN		1
				// <o> ���ƺ�״̬
					// <0=>  0 - �����Ϩ��
					// <1=>  1 - ������
					// <2=>  2 - һֱ��
					#define   CFG_UI_SCREEN_END_STATE_RL_IN		0
			// </e>	
			// <e> ���ذγ���RL_OUT��
			#define CFG_UI_SCREEN_RL_OUT			1
				// <o> ���ģʽѡ��
					// <0=>  0 - �޶���
					// <1=>  1 - Ϩ��
					// <2=>  2 - ����
					// <3=>  3 - ��˸
					// <4=>  4 - ά�ֵ�ǰ״̬
					// <5=>  5 - �����
					#define   CFG_UI_SCREEN_TYPE_RL_OUT		3
				// <o> ��/���ʱ����LSB=10ms��
					#define   CFG_UI_SCREEN_ONTIME_RL_OUT	20
				// <o> ���ƻ��ߺ�������
					#define   CFG_UI_SCREEN_CNT_RL_OUT		1
				// <o> ���ƺ�״̬
					// <0=>  0 - �����Ϩ��
					// <1=>  1 - ������
					// <2=>  2 - һֱ��
					#define   CFG_UI_SCREEN_END_STATE_RL_OUT		0
			// </e>			
			// <e> ���ض�·��RL_SHORT��
			#define CFG_UI_SCREEN_RL_SHORT			1
				// <o> ���ģʽѡ��
					// <0=>  0 - �޶���
					// <1=>  1 - Ϩ��
					// <2=>  2 - ����
					// <3=>  3 - ��˸
					// <4=>  4 - ά�ֵ�ǰ״̬
					// <5=>  5 - �����
					#define   CFG_UI_SCREEN_TYPE_RL_SHORT		3
				// <o> ��/���ʱ����LSB=10ms��
					#define   CFG_UI_SCREEN_ONTIME_RL_SHORT	20
				// <o> ���ƻ��ߺ�������
					#define   CFG_UI_SCREEN_CNT_RL_SHORT		10
				// <o> ���ƺ�״̬
					// <0=>  0 - �����Ϩ��
					// <1=>  1 - ������
					// <2=>  2 - һֱ��
					#define   CFG_UI_SCREEN_END_STATE_RL_SHORT		0
			// </e>	
			// <e> ���ص��裨RL_LOW��
			#define CFG_UI_SCREEN_RL_LOW			1
				// <o> ���ģʽѡ��
					// <0=>  0 - �޶���
					// <1=>  1 - Ϩ��
					// <2=>  2 - ����
					// <3=>  3 - ��˸
					// <4=>  4 - ά�ֵ�ǰ״̬
					// <5=>  5 - �����
					#define   CFG_UI_SCREEN_TYPE_RL_LOW		3
				// <o> ��/���ʱ����LSB=10ms��
					#define   CFG_UI_SCREEN_ONTIME_RL_LOW	20
				// <o> ���ƻ��ߺ�������
					#define   CFG_UI_SCREEN_CNT_RL_LOW		10
				// <o> ���ƺ�״̬
					// <0=>  0 - �����Ϩ��
					// <1=>  1 - ������
					// <2=>  2 - һֱ��
					#define   CFG_UI_SCREEN_END_STATE_RL_LOW		0
			// </e>			
			// <e> ���ؿ�·��RL_OPEN��
			#define CFG_UI_SCREEN_RL_OPEN			1
				// <o> ���ģʽѡ��
					// <0=>  0 - �޶���
					// <1=>  1 - Ϩ��
					// <2=>  2 - ����
					// <3=>  3 - ��˸
					// <4=>  4 - ά�ֵ�ǰ״̬
					// <5=>  5 - �����
					#define   CFG_UI_SCREEN_TYPE_RL_OPEN		3
				// <o> ��/���ʱ����LSB=10ms��
					#define   CFG_UI_SCREEN_ONTIME_RL_OPEN	20
				// <o> ���ƻ��ߺ�������
					#define   CFG_UI_SCREEN_CNT_RL_OPEN		5
				// <o> ���ƺ�״̬
					// <0=>  0 - �����Ϩ��
					// <1=>  1 - ������
					// <2=>  2 - һֱ��
					#define   CFG_UI_SCREEN_END_STATE_RL_OPEN		0
			// </e>			
			// <e> ���ظ��գ�RL_DRY��
			#define CFG_UI_SCREEN_RL_DRY			1
				// <o> ���ģʽѡ��
					// <0=>  0 - �޶���
					// <1=>  1 - Ϩ��
					// <2=>  2 - ����
					// <3=>  3 - ��˸
					// <4=>  4 - ά�ֵ�ǰ״̬
					// <5=>  5 - �����
					#define   CFG_UI_SCREEN_TYPE_RL_DRY		3
				// <o> ��/���ʱ����LSB=10ms��
					#define   CFG_UI_SCREEN_ONTIME_RL_DRY	20
				// <o> ���ƻ��ߺ�������
					#define   CFG_UI_SCREEN_CNT_RL_DRY		5
				// <o> ���ƺ�״̬
					// <0=>  0 - �����Ϩ��
					// <1=>  1 - ������
					// <2=>  2 - һֱ��
					#define   CFG_UI_SCREEN_END_STATE_RL_DRY		0
			// </e>			
			// <e> ����ͯ����CHILD_LOCK��
			#define CFG_UI_SCREEN_CHILD_LOCK			1
				// <o> ���ģʽѡ��
					// <0=>  0 - �޶���
					// <1=>  1 - Ϩ��
					// <2=>  2 - ����
					// <3=>  3 - ��˸
					// <4=>  4 - ά�ֵ�ǰ״̬
					// <5=>  5 - �����
					#define   CFG_UI_SCREEN_TYPE_CHILD_LOCK		3
				// <o> ��/���ʱ����LSB=10ms��
					#define   CFG_UI_SCREEN_ONTIME_CHILD_LOCK	50
				// <o> ���ƻ��ߺ�������
					#define   CFG_UI_SCREEN_CNT_CHILD_LOCK		2
				// <o> ���ƺ�״̬
					// <0=>  0 - �����Ϩ��
					// <1=>  1 - ������
					// <2=>  2 - һֱ��
					#define   CFG_UI_SCREEN_END_STATE_CHILD_LOCK		0
			// </e>			
			// <e> ͯ��������CHILD_UNLOCK��
			#define CFG_UI_SCREEN_CHILD_UNLOCK			1
				// <o> ���ģʽѡ��
					// <0=>  0 - �޶���
					// <1=>  1 - Ϩ��
					// <2=>  2 - ����
					// <3=>  3 - ��˸
					// <4=>  4 - ά�ֵ�ǰ״̬
					// <5=>  5 - �����
					#define   CFG_UI_SCREEN_TYPE_CHILD_UNLOCK		3
				// <o> ��/���ʱ����LSB=10ms��
					#define   CFG_UI_SCREEN_ONTIME_CHILD_UNLOCK	50
				// <o> ���ƻ��ߺ�������
					#define   CFG_UI_SCREEN_CNT_CHILD_UNLOCK		2
				// <o> ���ƺ�״̬
					// <0=>  0 - �����Ϩ��
					// <1=>  1 - ������
					// <2=>  2 - һֱ��
					#define   CFG_UI_SCREEN_END_STATE_CHILD_UNLOCK		0
			// </e>		
			// <e> ��ص�ѹ��BAT_LOW��
				#define CFG_UI_SCREEN_BAT_LOW			1
				// <o> ���ģʽѡ��
					// <0=>  0 - �޶���
					// <1=>  1 - Ϩ��
					// <2=>  2 - ����
					// <3=>  3 - ��˸
					// <4=>  4 - ά�ֵ�ǰ״̬
					// <5=>  5 - �����
					#define   CFG_UI_SCREEN_TYPE_BAT_LOW		3
				// <o> ��/���ʱ����LSB=10ms��
					#define   CFG_UI_SCREEN_ONTIME_BAT_LOW	20
				// <o> ���ƻ��ߺ�������
					#define   CFG_UI_SCREEN_CNT_BAT_LOW		20
				// <o> ���ƺ�״̬
					// <0=>  0 - �����Ϩ��
					// <1=>  1 - ������
					// <2=>  2 - һֱ��
					#define   CFG_UI_SCREEN_END_STATE_BAT_LOW		0
			// </e>			
			// <e> ϵͳ������SYS_LOCK��
				#define CFG_UI_SCREEN_SYS_LOCK			0
				// <o> ���ģʽѡ��
					// <0=>  0 - �޶���
					// <1=>  1 - Ϩ��
					// <2=>  2 - ����
					// <3=>  3 - ��˸
					// <4=>  4 - ά�ֵ�ǰ״̬
					// <5=>  5 - �����
					#define   CFG_UI_SCREEN_TYPE_SYS_LOCK		3
				// <o> ��/���ʱ����LSB=10ms��
					#define   CFG_UI_SCREEN_ONTIME_SYS_LOCK	20
				// <o> ���ƻ��ߺ�������
					#define   CFG_UI_SCREEN_CNT_SYS_LOCK		20
				// <o> ���ƺ�״̬
					// <0=>  0 - �����Ϩ��
					// <1=>  1 - ������
					// <2=>  2 - һֱ��
					#define   CFG_UI_SCREEN_END_STATE_SYS_LOCK		0
			// </e>			
			// <e> ϵͳ������SYS_UNLOCK��
				#define CFG_UI_SCREEN_SYS_UNLOCK			1
				// <o> ���ģʽѡ��
					// <0=>  0 - �޶���
					// <1=>  1 - Ϩ��
					// <2=>  2 - ����
					// <3=>  3 - ��˸
					// <4=>  4 - ά�ֵ�ǰ״̬
					// <5=>  5 - �����
					#define   CFG_UI_SCREEN_TYPE_SYS_UNLOCK		3
				// <o> ��/���ʱ����LSB=10ms��
					#define   CFG_UI_SCREEN_ONTIME_SYS_UNLOCK	20
				// <o> ���ƻ��ߺ�������
					#define   CFG_UI_SCREEN_CNT_SYS_UNLOCK		20
				// <o> ���ƺ�״̬
					// <0=>  0 - �����Ϩ��
					// <1=>  1 - ������
					// <2=>  2 - һֱ��
					#define   CFG_UI_SCREEN_END_STATE_SYS_UNLOCK		0
			// </e>		
			// <e> оƬ���£�CHIP_OTP��
				#define CFG_UI_SCREEN_CHIP_OTP			1
				// <o> ���ģʽѡ��
					// <0=>  0 - �޶���
					// <1=>  1 - Ϩ��
					// <2=>  2 - ����
					// <3=>  3 - ��˸
					// <4=>  4 - ά�ֵ�ǰ״̬
					// <5=>  5 - �����
					#define   CFG_UI_SCREEN_TYPE_CHIP_OTP		3
				// <o> ��/���ʱ����LSB=10ms��
					#define   CFG_UI_SCREEN_ONTIME_CHIP_OTP	50
				// <o> ���ƻ��ߺ�������
					#define   CFG_UI_SCREEN_CNT_CHIP_OTP		5
				// <o> ���ƺ�״̬
					// <0=>  0 - �����Ϩ��
					// <1=>  1 - ������
					// <2=>  2 - һֱ��
					#define   CFG_UI_SCREEN_END_STATE_CHIP_OTP		0
			// </e>			
		// </h>	
	// </e>
	// <e> �òʵƿ�������
		#define CFG_UI_MAGIC_LED_EN							0			
		// <e> ��Դ���ƹܽţ�˯�߹رյ�Դ��      
			#define CFG_UI_MAGIC_LED_PWR_EN					0	
			// <o> ʹ�õ�GPIO��
				// <i>Ĭ��: GPIOA��
				// <0x01=> GPIOA��
				// <0x02=> GPIOB��
				// <0x04=> GPIOC��
				#define CFG_PIN_MAGIC_LED_PWR_PORT			0x01
			// <o> ʹ���õ�GPIO��
				// <i>Ĭ��: PIN0
				// <0x01=> PIN0
				// <0x02=> PIN1
				// <0x04=> PIN2
				// <0x08=> PIN3
				#define CFG_PIN_MAGIC_LED_PWR_PINNUM		0x01
		// </e>		
		// <e> ���ƹܽ�1      
			#define CFG_UI_MAGIC_LED0_EN					0	
			// <o> ʹ�õ�GPIO��
				// <i>Ĭ��: GPIOA��
				// <0=> GPIOA��
				// <1=> GPIOB��
				// <2=> GPIOC��
				#define CFG_PIN_MAGIC_LED0_PORT			0
			// <o> ʹ���õ�GPIO��
				// <i>Ĭ��: PIN0
				// <0=> PIN0
				// <1=> PIN1
				// <2=> PIN2
				// <3=> PIN3
				#define CFG_PIN_MAGIC_LED0_PINNUM		1
		// </e>		
		// <e> ����ʾ����3���ƣ�      
			#define CFG_UI_MAGIC_LED_TEST_EN			0	
		// </e>			
	// </e>
// </h>

// <h> ��ص�����λ
	// <e> ���̵�ѹ����ʹ��
		// <i> Ĭ��:ʹ��
		#define CFG_BAT_UV_FIRE_EN				1	
		// <o> ����ǰǷѹ���ޣ�mV��
		#define   CFG_BAT_UV_IDLE_THD		3200
		// <o> ������Ƿѹ���ޣ�mV��
		#define   CFG_BAT_UV_FIRING_THD		2800		
	// </e>
		// <o> ��������/��С�Ĳ�����%��
		#define CFG_BAT_STEP						1	
	// <e> ����/���ʱ����ص�������ʹ��
		// <i> Ĭ��:ʧ��
		#define CFG_BAT_UPDATE_IDLE_EN				1		
		// <o> ���ʱ����ѹ̧��ƫ�mV��
		#define   CFG_BAT_DIFF_CHG					30	
		// <o> �������ڣ�ms��
		#define CFG_BAT_IDLE_UPDATA_TIME 			100			
		// <o> ���ʱ��δ���������������ڣ�LSB=100ms��
		#define CFG_CHG_NOT_PRE100_UPDATA_TIME 		200	
		// <o> ���ʱ���ѳ��������������ڣ�LSB=100ms��
		#define CFG_CHG_PRE100_UPDATA_TIME 			40		
	// </e>	
	// <e> ����ʱ����ص�������ʹ��
		// <i> Ĭ��:ʧ��
		#define CFG_BAT_UPDATE_FIRE_EN				1		
		// <o> �ŵ�ʱ����ѹ����ƫ�mV��
		#define   CFG_BAT_DIFF_DISCHG				30			
		// <o> �������ڣ�ms��
		#define CFG_BAT_FIRE_UPDATA_TIME 				100	
		// <o> ��������1%���ۼ�ʱ�䣨LSB=100ms��
		#define CFG_BAT_SUBB_PRE_1_TIME 			80		
		// <o> ֹͣ�������ʱ���µ�ص�����LSB=10ms��
			#define CFG_OUTPUT_STOP_UPDATE_BATTERY_TIME 100			
	// </e>		
// </h>

// <h> ���籣�����������ȫ���磩
	// <e> ��������
		// <i> Ĭ��:ʧ��
		#define CFG_OIL_CAL_EN						    1			
			// <o> ��������s��
			// <0-10000>
			#define CFG_OIL_MAX 						2200
			// <o> �����������ڣ�ms��
			#define CFG_OIL_UPDATA_TIME 				100			
	// </e>
// </h>

// <h> ���ڹ���
	// <e> Ӳ��UART����ʹ��
		// <i> Ĭ��:ʧ��
		#define CFG_UART_HW_EN						    1
			// <o> ���ڲ�����
				#define CFG_UART_BAUDRATE 				115200
			// <o> ���ڷ��ͻ�������С��Bytes��
				#define CFG_UART_TX_BUF_LENGTH 			32				
			// <o> ���ô��ڰ�˫��/ȫ˫���շ�
				// <i>Ĭ��: ȫ˫��
				// <0=> ȫ˫��
				// <1=> ��˫��
				#define CFG_UART_MODE					0
			// <e> ���ڽ���ʹ�ܣ���ʹ�ý��չ��ܣ��ɹرգ�
				// <i>Ĭ��: ʧ��
					#define CFG_UART_RX_EN				1
				// <o> ���ڽ��ջ�������С��Bytes��
					#define CFG_UART_RX_BUF_LENGTH 		10	
				// <o> ���ڽ������ݳ�ʱ��ms��
					#define CFG_UART_RX_TIMEOUT 		3		
			// </e>
			// <e> ���ڴ�������ʹ��(��Ҫ����RC1��GPIO���ѹ���)
				// <i>Ĭ��: ʧ��
					#define CFG_UART_BOOTING_EN			1
				// <o> ��������ָ��0
					#define CFG_UART_BOOTING_CMD0 		0x55
				// <o> ��������ָ��1
					#define CFG_UART_BOOTING_CMD1 		0x50
				// <o> ��������ָ��2
					#define CFG_UART_BOOTING_CMD2 		0x44					
				// <o> ��������ָ��3
					#define CFG_UART_BOOTING_CMD3 		0x41
				// <o> ��������ָ��4
					#define CFG_UART_BOOTING_CMD4 		0x54
				// <o> ��������ָ��5
					#define CFG_UART_BOOTING_CMD5 		0x45					
			// </e>			
			// <o> �����շ���ʽ
				// <i>Ĭ��: �����жϷ���
				// <0=> ������ѯ����
				// <1=> �����жϷ���
				#define CFG_UART_CONFIG_SEND_METHORD	0	
		// <e> Debug����ʹ�ܣ���������رգ�
			// <i> Ĭ��:ʧ��
			#define CFG_DEBUG_ON               			0
      
      // <e> ����ģʽ��ֻ��ӡ��ŵ���Ϣ��������ӡ����Ч��
      #define CFG_DEBUG_FACTORY_MODE          0
      //  </e>
      #if CFG_DEBUG_ON
        #if CFG_DEBUG_FACTORY_MODE
          #define   AM_FACTORY_PRINTF    tiny_printf
          #define   AM_DBG_PRINTF    /##/
        #else    
          #define   AM_FACTORY_PRINTF    /##/
          #define   AM_DBG_PRINTF    tiny_printf
        #endif
      #else
        #define   AM_FACTORY_PRINTF    /##/
        #define   AM_DBG_PRINTF    /##/
      #endif

		// </e>
    
    
	// </e>
// </h>

// <<< end of configuration section >>>

#endif /* end of __USER_CONFIG_H__ */
