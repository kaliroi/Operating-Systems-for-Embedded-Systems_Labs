/**
 * @file tpl_app_config.c
 *
 * @section desc File description
 *
 * OS data structure generated from application test
 * Automatically generated by goil on Fri Nov 17 15:11:38 2023
 * from root OIL file lab02_ex02.oil
 *
 * @section copyright Copyright
 *
 * Trampoline OS
 *
 * Trampoline is copyright (c) IRCCyN 2005-2007
 * Trampoline is protected by the French intellectual property law.
 *
 * This software is distributed under the Lesser GNU Public Licence
 *
 * @section infos File informations
 *
 * $Date$
 * $Rev$
 * $Author$
 * $URL$
 */

#include <stdbool.h>
#include <stdint.h>

#include "tpl_app_config.h"

#include "tpl_os_internal_types.h"
#include "tpl_machine.h"
#include "tpl_os_interrupt.h"
#include "tpl_os_interrupt_kernel.h"
#include "tpl_os_alarm_kernel.h"
#include "tpl_os_alarm.h"
#include "tpl_os_resource_kernel.h"
#include "tpl_os_resource.h"
#include "tpl_os_event_kernel.h"
#include "tpl_os_event.h"
#include "tpl_os_action.h"
#include "tpl_os_kernel.h"
#include "tpl_os_definitions.h"


#include "tpl_com_notification.h"
#include "tpl_com_mo.h"
#include "tpl_com_internal.h"
#include "tpl_com_internal_com.h"
/*#include "tpl_com_external_com.h"*/
#include "tpl_com_app_copy.h"
#include "tpl_com_filters.h"

/*=============================================================================
 * Application Modes tables for tasks, alarms and schedule tables
 * Application Modes masks are as follow:
 * stdAppmode = 1
 */

CONST(tpl_application_mode, OS_CONST) stdAppmode = 0; /* mask = 1 */
CONST(tpl_application_mode, OS_CONST) OSDEFAULTAPPMODE = 0;
CONST(tpl_appmode_mask, OS_CONST) tpl_task_app_mode[TASK_COUNT] = {
  0 /* task TaskV :  */ ,
  0 /* task TaskM :  */ ,
  0 /* task TaskC :  */ ,
  0 /* task stop :  */ 
};

CONST(tpl_appmode_mask, OS_CONST) tpl_alarm_app_mode[ALARM_COUNT] = {
  1 /* alarm Cperiod100ms : stdAppmode */ ,
  1 /* alarm Vperiod25ms : stdAppmode */ ,
  1 /* alarm stopper : stdAppmode */ 
};

#define API_START_SEC_CONST_UNSPECIFIED
#include "tpl_memmap.h"

/*=============================================================================
 * Declaration of processes IDs
 */

/* Task TaskV identifier */
#define TaskV_id 0
CONST(TaskType, AUTOMATIC) TaskV = TaskV_id;

/* Task TaskM identifier */
#define TaskM_id 1
CONST(TaskType, AUTOMATIC) TaskM = TaskM_id;

/* Task TaskC identifier */
#define TaskC_id 2
CONST(TaskType, AUTOMATIC) TaskC = TaskC_id;

/* Task stop identifier */
#define stop_id 3
CONST(TaskType, AUTOMATIC) stop = stop_id;

/*=============================================================================
 * Declaration of Alarm IDs
 */

/* Alarm Cperiod100ms identifier */
#define Cperiod100ms_id 0
CONST(AlarmType, AUTOMATIC) Cperiod100ms = Cperiod100ms_id;

/* Alarm Vperiod25ms identifier */
#define Vperiod25ms_id 1
CONST(AlarmType, AUTOMATIC) Vperiod25ms = Vperiod25ms_id;

/* Alarm stopper identifier */
#define stopper_id 2
CONST(AlarmType, AUTOMATIC) stopper = stopper_id;

/*=============================================================================
 * Declaration of receive messages IDs
 */

/* Message msgCrec identifier */
#define msgCrec_id 0
CONST(MessageIdentifier, AUTOMATIC) msgCrec = msgCrec_id;

/* Message msgMrec identifier */
#define msgMrec_id 1
CONST(MessageIdentifier, AUTOMATIC) msgMrec = msgMrec_id;

/*=============================================================================
 * Declaration of send messages IDs
 */

/* Message msgCsend identifier */
#define msgCsend_id 0
CONST(MessageIdentifier, AUTOMATIC) msgCsend = msgCsend_id;

/* Message msgMsend identifier */
#define msgMsend_id 1
CONST(MessageIdentifier, AUTOMATIC) msgMsend = msgMsend_id;

#define API_STOP_SEC_CONST_UNSPECIFIED
#include "tpl_memmap.h"

/**
 * The scheduler resource descriptor.
 * One scheduler resource is defined per core.
 *
 * @see #RES_SCHEDULER
 */

#define OS_START_SEC_VAR_UNSPECIFIED
#include "tpl_memmap.h"
VAR(tpl_resource, OS_VAR) res_sched_rez_desc = {
  RES_SCHEDULER_PRIORITY,   /*  ceiling priority                            */
  0,                        /*  owner_prev_priority                         */
  INVALID_PROC_ID,          /*  owner                                       */
#if WITH_OSAPPLICATION == YES
  INVALID_OSAPPLICATION_ID, /*  OS Application id                           */
#endif

  NULL                      /*  next_res                                    */
};
#define OS_STOP_SEC_VAR_UNSPECIFIED
#include "tpl_memmap.h"

#define OS_START_SEC_CONST_UNSPECIFIED
#include "tpl_memmap.h"
CONSTP2VAR(tpl_resource, AUTOMATIC, OS_APPL_DATA)
tpl_resource_table[RESOURCE_COUNT] = {
  &res_sched_rez_desc
};

#define OS_STOP_SEC_CONST_UNSPECIFIED
#include "tpl_memmap.h"

/*=============================================================================
 * Definition and initialization of Counters related defines and structures
 */
/*-----------------------------------------------------------------------------
 * Counter SystemCounter descriptor
 */

#define API_START_SEC_CONST_UNSPECIFIED
#include "tpl_memmap.h"

CONST(tpl_tick, OS_CONST) OSTICKSPERBASE = 1;
CONST(tpl_tick, OS_CONST) OSMAXALLOWEDVALUE = 65535;
CONST(tpl_tick, OS_CONST) OSMINCYCLE = 1;

#define API_STOP_SEC_CONST_UNSPECIFIED
#include "tpl_memmap.h"

#define OS_START_SEC_VAR_UNSPECIFIED
#include "tpl_memmap.h"

VAR(tpl_counter, OS_VAR) SystemCounter_counter_desc = {
  /* ticks per base       */  1,
  /* max allowed value    */  65535,
  /* minimum cycle        */  1,
  /* current tick         */  0,
  /* current date         */  0,
#if WITH_OSAPPLICATION == YES
    /* OS Application id    */  
#endif
    /* first alarm          */  NULL_PTR,
    /* next alarm to raise  */  NULL_PTR
};

#define OS_STOP_SEC_VAR_UNSPECIFIED
#include "tpl_memmap.h"

#include "tpl_os_kernel.h"          /* tpl_schedule */
#include "tpl_os_timeobj_kernel.h"  /* tpl_counter_tick */
#include "tpl_machine_interface.h"  /* tpl_switch_context_from_it */

#define OS_START_SEC_CODE
#include "tpl_memmap.h"

//gcc uses ISR as a keyword to define an interrupt handler.
//Osek uses ISR to define an ISR2 :-/
#ifdef ISR
 #undef ISR
#endif
#include <avr/interrupt.h>

//function defined in avr assembly files.
FUNC(void, OS_CODE) tpl_avr_counter_tick(
    P2VAR(tpl_counter, AUTOMATIC, OS_APPL_DATA) counter);


void trampolineSystemCounter()
{
  tpl_avr_counter_tick(&SystemCounter_counter_desc);
}
  
#define OS_STOP_SEC_CODE
#include "tpl_memmap.h"

/*=============================================================================
 * Descriptor(s) of the idle task(s)
 */
/*-----------------------------------------------------------------------------
 * Task IDLE_TASK descriptor
 */
#define OS_START_SEC_CODE
#include "tpl_memmap.h"
/*
 * Task IDLE_TASK function prototype
 */

FUNC(void, OS_APPL_CODE) idle_function(void);
#define OS_STOP_SEC_CODE
#include "tpl_memmap.h"

/*-----------------------------------------------------------------------------
 * Target specific structures
 */

/*
 * Task IDLE_TASK stack
 *
 */
#define APP_Task_IDLE_TASK_START_SEC_STACK
#include "tpl_memmap.h"
tpl_stack_word IDLE_TASK_stack_zone[IDLE_STACK_SIZE/sizeof(tpl_stack_word)];
#define APP_Task_IDLE_TASK_STOP_SEC_STACK
#include "tpl_memmap.h"

#define OS_START_SEC_VAR_UNSPECIFIED
#include "tpl_memmap.h"

#define IDLE_TASK_STACK { IDLE_TASK_stack_zone, IDLE_STACK_SIZE }

/*
 * Task IDLE_TASK context
 */
avr_context IDLE_TASK_int_context;
#define IDLE_TASK_CONTEXT &IDLE_TASK_int_context

#define OS_STOP_SEC_VAR_UNSPECIFIED
#include "tpl_memmap.h"




/*
  No timing protection
 */

#define OS_START_SEC_CONST_UNSPECIFIED
#include "tpl_memmap.h"


/*
 * Static descriptor of task IDLE_TASK
 */
CONST(tpl_proc_static, OS_CONST) IDLE_TASK_task_stat_desc = {
  /* context                  */  IDLE_TASK_CONTEXT,
  /* stack                    */  IDLE_TASK_STACK,
  /* entry point (function)   */  idle_function,
  /* internal ressource       */  NULL,
  /* task id                  */  IDLE_TASK_ID,
#if WITH_OSAPPLICATION == YES
  /* OS application id        */  
#endif
  /* task base priority       */  0,
  /* max activation count     */  1,
  /* task type                */  TASK_BASIC,
#if WITH_AUTOSAR_TIMING_PROTECTION == YES

  /* execution budget */        0,
  /* timeframe        */        0, 
  /* pointer to the timing
     protection descriptor    */ NULL

#endif
};

#define OS_STOP_SEC_CONST_UNSPECIFIED
#include "tpl_memmap.h"


#define OS_START_SEC_VAR_UNSPECIFIED
#include "tpl_memmap.h"
/*
 * Dynamic descriptor of task IDLE_TASK
 */
VAR(tpl_proc, OS_VAR) IDLE_TASK_task_desc = {
  /* resources                      */  NULL,
#if WITH_OSAPPLICATION == YES
  /* if > 0 the process is trusted  */  0,    
#endif /* WITH_OSAPPLICATION */
  /* activate count                 */  0,
  /* task priority                  */  0,
  /* task state                     */  SUSPENDED
};

#define OS_STOP_SEC_VAR_UNSPECIFIED
#include "tpl_memmap.h"


/*=============================================================================
 * Definition and initialization of Task related defines and structures
 */
/*-----------------------------------------------------------------------------
 * Task TaskV descriptor
 */
#define APP_Task_TaskV_START_SEC_CODE

#include "tpl_memmap.h"
/*
 * Task TaskV function prototype
 */

FUNC(void, OS_APPL_CODE) TaskV_function(void);
#define APP_Task_TaskV_STOP_SEC_CODE

#include "tpl_memmap.h"

/*-----------------------------------------------------------------------------
 * Target specific structures
 */

/*
 * Task TaskV stack
 *
 */
#define APP_Task_TaskV_START_SEC_STACK
#include "tpl_memmap.h"
tpl_stack_word TaskV_stack_zone[256/sizeof(tpl_stack_word)];
#define APP_Task_TaskV_STOP_SEC_STACK
#include "tpl_memmap.h"

#define OS_START_SEC_VAR_UNSPECIFIED
#include "tpl_memmap.h"

#define TaskV_STACK { TaskV_stack_zone, 256 }

/*
 * Task TaskV context
 */
avr_context TaskV_int_context;
#define TaskV_CONTEXT &TaskV_int_context

#define OS_STOP_SEC_VAR_UNSPECIFIED
#include "tpl_memmap.h"




/*
  No timing protection
 */

#define OS_START_SEC_CONST_UNSPECIFIED
#include "tpl_memmap.h"


/*
 * Static descriptor of task TaskV
 */
CONST(tpl_proc_static, OS_CONST) TaskV_task_stat_desc = {
  /* context                  */  TaskV_CONTEXT,
  /* stack                    */  TaskV_STACK,
  /* entry point (function)   */  TaskV_function,
  /* internal ressource       */  NULL,
  /* task id                  */  TaskV_id,
#if WITH_OSAPPLICATION == YES
  /* OS application id        */  
#endif
  /* task base priority       */  1,
  /* max activation count     */  1,
  /* task type                */  TASK_BASIC,
#if WITH_AUTOSAR_TIMING_PROTECTION == YES

  /* execution budget */        0,
  /* timeframe        */        0, 
  /* pointer to the timing
     protection descriptor    */ NULL

#endif
};

#define OS_STOP_SEC_CONST_UNSPECIFIED
#include "tpl_memmap.h"


#define OS_START_SEC_VAR_UNSPECIFIED
#include "tpl_memmap.h"
/*
 * Dynamic descriptor of task TaskV
 */
VAR(tpl_proc, OS_VAR) TaskV_task_desc = {
  /* resources                      */  NULL,
#if WITH_OSAPPLICATION == YES
  /* if > 0 the process is trusted  */  0,    
#endif /* WITH_OSAPPLICATION */
  /* activate count                 */  0,
  /* task priority                  */  1,
  /* task state                     */  SUSPENDED
};

#define OS_STOP_SEC_VAR_UNSPECIFIED
#include "tpl_memmap.h"

/*-----------------------------------------------------------------------------
 * Task TaskM descriptor
 */
#define APP_Task_TaskM_START_SEC_CODE

#include "tpl_memmap.h"
/*
 * Task TaskM function prototype
 */

FUNC(void, OS_APPL_CODE) TaskM_function(void);
#define APP_Task_TaskM_STOP_SEC_CODE

#include "tpl_memmap.h"

/*-----------------------------------------------------------------------------
 * Target specific structures
 */

/*
 * Task TaskM stack
 *
 */
#define APP_Task_TaskM_START_SEC_STACK
#include "tpl_memmap.h"
tpl_stack_word TaskM_stack_zone[256/sizeof(tpl_stack_word)];
#define APP_Task_TaskM_STOP_SEC_STACK
#include "tpl_memmap.h"

#define OS_START_SEC_VAR_UNSPECIFIED
#include "tpl_memmap.h"

#define TaskM_STACK { TaskM_stack_zone, 256 }

/*
 * Task TaskM context
 */
avr_context TaskM_int_context;
#define TaskM_CONTEXT &TaskM_int_context

#define OS_STOP_SEC_VAR_UNSPECIFIED
#include "tpl_memmap.h"




/*
  No timing protection
 */

#define OS_START_SEC_CONST_UNSPECIFIED
#include "tpl_memmap.h"


/*
 * Static descriptor of task TaskM
 */
CONST(tpl_proc_static, OS_CONST) TaskM_task_stat_desc = {
  /* context                  */  TaskM_CONTEXT,
  /* stack                    */  TaskM_STACK,
  /* entry point (function)   */  TaskM_function,
  /* internal ressource       */  NULL,
  /* task id                  */  TaskM_id,
#if WITH_OSAPPLICATION == YES
  /* OS application id        */  
#endif
  /* task base priority       */  2,
  /* max activation count     */  1,
  /* task type                */  TASK_BASIC,
#if WITH_AUTOSAR_TIMING_PROTECTION == YES

  /* execution budget */        0,
  /* timeframe        */        0, 
  /* pointer to the timing
     protection descriptor    */ NULL

#endif
};

#define OS_STOP_SEC_CONST_UNSPECIFIED
#include "tpl_memmap.h"


#define OS_START_SEC_VAR_UNSPECIFIED
#include "tpl_memmap.h"
/*
 * Dynamic descriptor of task TaskM
 */
VAR(tpl_proc, OS_VAR) TaskM_task_desc = {
  /* resources                      */  NULL,
#if WITH_OSAPPLICATION == YES
  /* if > 0 the process is trusted  */  0,    
#endif /* WITH_OSAPPLICATION */
  /* activate count                 */  0,
  /* task priority                  */  2,
  /* task state                     */  SUSPENDED
};

#define OS_STOP_SEC_VAR_UNSPECIFIED
#include "tpl_memmap.h"

/*-----------------------------------------------------------------------------
 * Task TaskC descriptor
 */
#define APP_Task_TaskC_START_SEC_CODE

#include "tpl_memmap.h"
/*
 * Task TaskC function prototype
 */

FUNC(void, OS_APPL_CODE) TaskC_function(void);
#define APP_Task_TaskC_STOP_SEC_CODE

#include "tpl_memmap.h"

/*-----------------------------------------------------------------------------
 * Target specific structures
 */

/*
 * Task TaskC stack
 *
 */
#define APP_Task_TaskC_START_SEC_STACK
#include "tpl_memmap.h"
tpl_stack_word TaskC_stack_zone[256/sizeof(tpl_stack_word)];
#define APP_Task_TaskC_STOP_SEC_STACK
#include "tpl_memmap.h"

#define OS_START_SEC_VAR_UNSPECIFIED
#include "tpl_memmap.h"

#define TaskC_STACK { TaskC_stack_zone, 256 }

/*
 * Task TaskC context
 */
avr_context TaskC_int_context;
#define TaskC_CONTEXT &TaskC_int_context

#define OS_STOP_SEC_VAR_UNSPECIFIED
#include "tpl_memmap.h"




/*
  No timing protection
 */

#define OS_START_SEC_CONST_UNSPECIFIED
#include "tpl_memmap.h"


/*
 * Static descriptor of task TaskC
 */
CONST(tpl_proc_static, OS_CONST) TaskC_task_stat_desc = {
  /* context                  */  TaskC_CONTEXT,
  /* stack                    */  TaskC_STACK,
  /* entry point (function)   */  TaskC_function,
  /* internal ressource       */  NULL,
  /* task id                  */  TaskC_id,
#if WITH_OSAPPLICATION == YES
  /* OS application id        */  
#endif
  /* task base priority       */  3,
  /* max activation count     */  1,
  /* task type                */  TASK_BASIC,
#if WITH_AUTOSAR_TIMING_PROTECTION == YES

  /* execution budget */        0,
  /* timeframe        */        0, 
  /* pointer to the timing
     protection descriptor    */ NULL

#endif
};

#define OS_STOP_SEC_CONST_UNSPECIFIED
#include "tpl_memmap.h"


#define OS_START_SEC_VAR_UNSPECIFIED
#include "tpl_memmap.h"
/*
 * Dynamic descriptor of task TaskC
 */
VAR(tpl_proc, OS_VAR) TaskC_task_desc = {
  /* resources                      */  NULL,
#if WITH_OSAPPLICATION == YES
  /* if > 0 the process is trusted  */  0,    
#endif /* WITH_OSAPPLICATION */
  /* activate count                 */  0,
  /* task priority                  */  3,
  /* task state                     */  SUSPENDED
};

#define OS_STOP_SEC_VAR_UNSPECIFIED
#include "tpl_memmap.h"

/*-----------------------------------------------------------------------------
 * Task stop descriptor
 */
#define APP_Task_stop_START_SEC_CODE

#include "tpl_memmap.h"
/*
 * Task stop function prototype
 */

FUNC(void, OS_APPL_CODE) stop_function(void);
#define APP_Task_stop_STOP_SEC_CODE

#include "tpl_memmap.h"

/*-----------------------------------------------------------------------------
 * Target specific structures
 */

/*
 * Task stop stack
 *
 */
#define APP_Task_stop_START_SEC_STACK
#include "tpl_memmap.h"
tpl_stack_word stop_stack_zone[256/sizeof(tpl_stack_word)];
#define APP_Task_stop_STOP_SEC_STACK
#include "tpl_memmap.h"

#define OS_START_SEC_VAR_UNSPECIFIED
#include "tpl_memmap.h"

#define stop_STACK { stop_stack_zone, 256 }

/*
 * Task stop context
 */
avr_context stop_int_context;
#define stop_CONTEXT &stop_int_context

#define OS_STOP_SEC_VAR_UNSPECIFIED
#include "tpl_memmap.h"




/*
  No timing protection
 */

#define OS_START_SEC_CONST_UNSPECIFIED
#include "tpl_memmap.h"


/*
 * Static descriptor of task stop
 */
CONST(tpl_proc_static, OS_CONST) stop_task_stat_desc = {
  /* context                  */  stop_CONTEXT,
  /* stack                    */  stop_STACK,
  /* entry point (function)   */  stop_function,
  /* internal ressource       */  NULL,
  /* task id                  */  stop_id,
#if WITH_OSAPPLICATION == YES
  /* OS application id        */  
#endif
  /* task base priority       */  4,
  /* max activation count     */  1,
  /* task type                */  TASK_BASIC,
#if WITH_AUTOSAR_TIMING_PROTECTION == YES

  /* execution budget */        0,
  /* timeframe        */        0, 
  /* pointer to the timing
     protection descriptor    */ NULL

#endif
};

#define OS_STOP_SEC_CONST_UNSPECIFIED
#include "tpl_memmap.h"


#define OS_START_SEC_VAR_UNSPECIFIED
#include "tpl_memmap.h"
/*
 * Dynamic descriptor of task stop
 */
VAR(tpl_proc, OS_VAR) stop_task_desc = {
  /* resources                      */  NULL,
#if WITH_OSAPPLICATION == YES
  /* if > 0 the process is trusted  */  0,    
#endif /* WITH_OSAPPLICATION */
  /* activate count                 */  0,
  /* task priority                  */  4,
  /* task state                     */  SUSPENDED
};

#define OS_STOP_SEC_VAR_UNSPECIFIED
#include "tpl_memmap.h"


#include "tpl_machine.h"
#define OS_START_SEC_CODE
#include "tpl_memmap.h"

//function defined in avr assembly files.
FUNC(void, OS_CODE) tpl_avr_ISR2_handler(CONST(uint16, AUTOMATIC) id);


#define OS_STOP_SEC_CODE
#include "tpl_memmap.h"

#define OS_START_SEC_CONST_UNSPECIFIED
#include "tpl_memmap.h"
/*=============================================================================
 * Definition and initialization of process tables (tasks and isrs)
 */
CONSTP2CONST(tpl_proc_static, AUTOMATIC, OS_APPL_DATA)
tpl_stat_proc_table[TASK_COUNT+ISR_COUNT+1] = {
  &TaskV_task_stat_desc,
  &TaskM_task_stat_desc,
  &TaskC_task_stat_desc,
  &stop_task_stat_desc,
  &IDLE_TASK_task_stat_desc
};

CONSTP2VAR(tpl_proc, AUTOMATIC, OS_APPL_DATA)
tpl_dyn_proc_table[TASK_COUNT+ISR_COUNT+1] = {
  &TaskV_task_desc,
  &TaskM_task_desc,
  &TaskC_task_desc,
  &stop_task_desc,
  &IDLE_TASK_task_desc
};

#define OS_STOP_SEC_CONST_UNSPECIFIED
#include "tpl_memmap.h"


/*=============================================================================
 * Definition and initialization of Alarm related structures
 */
/*-----------------------------------------------------------------------------
 * Alarm Cperiod100ms descriptor
 *
 * This alarm does the activation of task TaskC
 */


#define OS_START_SEC_CONST_UNSPECIFIED
#include "tpl_memmap.h"

CONST(tpl_task_activation_action, OS_CONST) Cperiod100ms_action = {
  {
    /* action function  */  tpl_action_activate_task
  },
  /* task id            */  TaskC_id
};

#define OS_STOP_SEC_CONST_UNSPECIFIED
#include "tpl_memmap.h"
 
#define OS_START_SEC_CONST_UNSPECIFIED
#include "tpl_memmap.h"

CONST(tpl_alarm_static, OS_CONST) Cperiod100ms_static = {
  {
    /* pointer to counter           */  &SystemCounter_counter_desc,
    /* pointer to the expiration    */  tpl_raise_alarm
#if (WITH_ID == YES)
    /* id of the alarm for tracing  */  , Cperiod100ms_id
#endif
#if WITH_OSAPPLICATION == YES
    /* OS application id            */  , 
#endif
  },
  /* action of the alarm  */  (tpl_action *)&Cperiod100ms_action
};

#define OS_STOP_SEC_CONST_UNSPECIFIED
#include "tpl_memmap.h"

#define OS_START_SEC_VAR_UNSPECIFIED
#include "tpl_memmap.h"

VAR(tpl_time_obj, OS_VAR) Cperiod100ms_alarm_desc = {
    /* pointer to the static part   */  (tpl_time_obj_static *)&Cperiod100ms_static,
    /* next alarm                   */  NULL,
    /* prev alarm                   */  NULL,
    /* cycle                        */  100,
    /* date                         */  100,
    /* State of the alarm           */  ALARM_AUTOSTART
};

#define OS_STOP_SEC_VAR_UNSPECIFIED
#include "tpl_memmap.h"

/*-----------------------------------------------------------------------------
 * Alarm Vperiod25ms descriptor
 *
 * This alarm does the activation of task TaskV
 */


#define OS_START_SEC_CONST_UNSPECIFIED
#include "tpl_memmap.h"

CONST(tpl_task_activation_action, OS_CONST) Vperiod25ms_action = {
  {
    /* action function  */  tpl_action_activate_task
  },
  /* task id            */  TaskV_id
};

#define OS_STOP_SEC_CONST_UNSPECIFIED
#include "tpl_memmap.h"
 
#define OS_START_SEC_CONST_UNSPECIFIED
#include "tpl_memmap.h"

CONST(tpl_alarm_static, OS_CONST) Vperiod25ms_static = {
  {
    /* pointer to counter           */  &SystemCounter_counter_desc,
    /* pointer to the expiration    */  tpl_raise_alarm
#if (WITH_ID == YES)
    /* id of the alarm for tracing  */  , Vperiod25ms_id
#endif
#if WITH_OSAPPLICATION == YES
    /* OS application id            */  , 
#endif
  },
  /* action of the alarm  */  (tpl_action *)&Vperiod25ms_action
};

#define OS_STOP_SEC_CONST_UNSPECIFIED
#include "tpl_memmap.h"

#define OS_START_SEC_VAR_UNSPECIFIED
#include "tpl_memmap.h"

VAR(tpl_time_obj, OS_VAR) Vperiod25ms_alarm_desc = {
    /* pointer to the static part   */  (tpl_time_obj_static *)&Vperiod25ms_static,
    /* next alarm                   */  NULL,
    /* prev alarm                   */  NULL,
    /* cycle                        */  25,
    /* date                         */  100,
    /* State of the alarm           */  ALARM_AUTOSTART
};

#define OS_STOP_SEC_VAR_UNSPECIFIED
#include "tpl_memmap.h"

/*-----------------------------------------------------------------------------
 * Alarm stopper descriptor
 *
 * This alarm does the activation of task stop
 */


#define OS_START_SEC_CONST_UNSPECIFIED
#include "tpl_memmap.h"

CONST(tpl_task_activation_action, OS_CONST) stopper_action = {
  {
    /* action function  */  tpl_action_activate_task
  },
  /* task id            */  stop_id
};

#define OS_STOP_SEC_CONST_UNSPECIFIED
#include "tpl_memmap.h"
 
#define OS_START_SEC_CONST_UNSPECIFIED
#include "tpl_memmap.h"

CONST(tpl_alarm_static, OS_CONST) stopper_static = {
  {
    /* pointer to counter           */  &SystemCounter_counter_desc,
    /* pointer to the expiration    */  tpl_raise_alarm
#if (WITH_ID == YES)
    /* id of the alarm for tracing  */  , stopper_id
#endif
#if WITH_OSAPPLICATION == YES
    /* OS application id            */  , 
#endif
  },
  /* action of the alarm  */  (tpl_action *)&stopper_action
};

#define OS_STOP_SEC_CONST_UNSPECIFIED
#include "tpl_memmap.h"

#define OS_START_SEC_VAR_UNSPECIFIED
#include "tpl_memmap.h"

VAR(tpl_time_obj, OS_VAR) stopper_alarm_desc = {
    /* pointer to the static part   */  (tpl_time_obj_static *)&stopper_static,
    /* next alarm                   */  NULL,
    /* prev alarm                   */  NULL,
    /* cycle                        */  0,
    /* date                         */  40000,
    /* State of the alarm           */  ALARM_AUTOSTART
};

#define OS_STOP_SEC_VAR_UNSPECIFIED
#include "tpl_memmap.h"


#define OS_START_SEC_CONST_UNSPECIFIED
#include "tpl_memmap.h"
CONSTP2VAR(tpl_time_obj, AUTOMATIC, OS_APPL_DATA)
  tpl_alarm_table[ALARM_COUNT] = {
  &Cperiod100ms_alarm_desc,
  &Vperiod25ms_alarm_desc,
  &stopper_alarm_desc
};
#define OS_STOP_SEC_CONST_UNSPECIFIED
#include "tpl_memmap.h"

/*=============================================================================
 * Declaration of flags functions
 */
/* $FLAGSFUNCTIONS$ */


/*=============================================================================
 * Definition and initialization of Receive Messages related structures
 */

/*-----------------------------------------------------------------------------
 * Action of message msgCrec
 */

#define OS_START_SEC_CONST_UNSPECIFIED
#include "tpl_memmap.h"

CONST(tpl_task_activation_action, OS_CONST) msgCrec_action = {
  {
    /* action function  */  tpl_action_activate_task
  },
  /* task id            */  TaskM_id
};

#define OS_STOP_SEC_CONST_UNSPECIFIED
#include "tpl_memmap.h"
/*-----------------------------------------------------------------------------
 * ALWAYS filter of message object msgCrec
 */
#define OS_START_SEC_CONST_UNSPECIFIED
#include "tpl_memmap.h"

tpl_noparam_filter_desc msgCrec_filter = {
    /*  filtering function          */  tpl_filter_always
};

#define OS_STOP_SEC_CONST_UNSPECIFIED
#include "tpl_memmap.h"

/*-----------------------------------------------------------------------------
 * Static internal receiving unqueued message object msgCrec
 */
#define OS_START_SEC_VAR_UNSPECIFIED
#include "tpl_memmap.h"

VAR(int, OS_VAR) msgCrec_buffer;

#define OS_STOP_SEC_VAR_UNSPECIFIED
#include "tpl_memmap.h"

#define OS_START_SEC_CONST_UNSPECIFIED
#include "tpl_memmap.h"

CONST(tpl_internal_receiving_unqueued_mo, OS_CONST) msgCrec_message = {
  { /* data receiving mo struct   */
    { /* base receiving mo struct */
      /* notification pointer     */  (tpl_action *)&msgCrec_action,
      /*  next receiving mo       */  NULL
    },
    /*  receiving function      */  (tpl_receiving_func)tpl_receive_static_internal_unqueued_message,
    /*  copy function           */  (tpl_data_copy_func)tpl_copy_from_unqueued,
    /*  filter pointer          */  (tpl_filter_desc *)&msgCrec_filter
  },
  { /* buffer struct    */
    /*  buffer  */  (tpl_com_data *)&msgCrec_buffer,
    /*  size    */  sizeof(int)
  }
};

#define OS_STOP_SEC_CONST_UNSPECIFIED
#include "tpl_memmap.h"

/*-----------------------------------------------------------------------------
 * Action of message msgMrec
 */

#define OS_START_SEC_CONST_UNSPECIFIED
#include "tpl_memmap.h"

CONST(tpl_task_activation_action, OS_CONST) msgMrec_action = {
  {
    /* action function  */  tpl_action_activate_task
  },
  /* task id            */  TaskV_id
};

#define OS_STOP_SEC_CONST_UNSPECIFIED
#include "tpl_memmap.h"
/*-----------------------------------------------------------------------------
 * ALWAYS filter of message object msgMrec
 */
#define OS_START_SEC_CONST_UNSPECIFIED
#include "tpl_memmap.h"

tpl_noparam_filter_desc msgMrec_filter = {
    /*  filtering function          */  tpl_filter_always
};

#define OS_STOP_SEC_CONST_UNSPECIFIED
#include "tpl_memmap.h"

/*-----------------------------------------------------------------------------
 * Static internal receiving unqueued message object msgMrec
 */
#define OS_START_SEC_VAR_UNSPECIFIED
#include "tpl_memmap.h"

VAR(int, OS_VAR) msgMrec_buffer;

#define OS_STOP_SEC_VAR_UNSPECIFIED
#include "tpl_memmap.h"

#define OS_START_SEC_CONST_UNSPECIFIED
#include "tpl_memmap.h"

CONST(tpl_internal_receiving_unqueued_mo, OS_CONST) msgMrec_message = {
  { /* data receiving mo struct   */
    { /* base receiving mo struct */
      /* notification pointer     */  (tpl_action *)&msgMrec_action,
      /*  next receiving mo       */  NULL
    },
    /*  receiving function      */  (tpl_receiving_func)tpl_receive_static_internal_unqueued_message,
    /*  copy function           */  (tpl_data_copy_func)tpl_copy_from_unqueued,
    /*  filter pointer          */  (tpl_filter_desc *)&msgMrec_filter
  },
  { /* buffer struct    */
    /*  buffer  */  (tpl_com_data *)&msgMrec_buffer,
    /*  size    */  sizeof(int)
  }
};

#define OS_STOP_SEC_CONST_UNSPECIFIED
#include "tpl_memmap.h"

/*=============================================================================
 * Definition and initialization of the receive messages table
 */
#define OS_START_SEC_CONST_UNSPECIFIED
#include "tpl_memmap.h"

CONSTP2CONST(tpl_base_receiving_mo, AUTOMATIC, OS_CONST)
tpl_receive_message_table[RECEIVE_MESSAGE_COUNT] = {
  (tpl_base_receiving_mo*)&msgCrec_message,    
  (tpl_base_receiving_mo*)&msgMrec_message
};

#define OS_STOP_SEC_CONST_UNSPECIFIED
#include "tpl_memmap.h"

/*=============================================================================
 * Definition and initialization of Send Messages related structures
 */
#define OS_START_SEC_CONST_UNSPECIFIED
#include "tpl_memmap.h"

/*-----------------------------------------------------------------------------
 * Static internal sending static message object msgCsend
 */
CONST(tpl_internal_sending_mo, OS_CONST) msgCsend_message = {
  { /* base message object       */
    /* sending function          */ tpl_send_static_internal_message
  },
  /* pointer to the receiving mo */ (tpl_base_receiving_mo *)&msgCrec_message
};

#define OS_STOP_SEC_CONST_UNSPECIFIED
#include "tpl_memmap.h"

#define OS_START_SEC_CONST_UNSPECIFIED
#include "tpl_memmap.h"

/*-----------------------------------------------------------------------------
 * Static internal sending static message object msgMsend
 */
CONST(tpl_internal_sending_mo, OS_CONST) msgMsend_message = {
  { /* base message object       */
    /* sending function          */ tpl_send_static_internal_message
  },
  /* pointer to the receiving mo */ (tpl_base_receiving_mo *)&msgMrec_message
};

#define OS_STOP_SEC_CONST_UNSPECIFIED
#include "tpl_memmap.h"


/*=============================================================================
 * Definition and initialization of the send messages table
 */
#define OS_START_SEC_CONST_UNSPECIFIED
#include "tpl_memmap.h"

CONSTP2CONST(tpl_base_sending_mo, AUTOMATIC, OS_CONST)
tpl_send_message_table[SEND_MESSAGE_COUNT] = {
  (tpl_base_sending_mo*)&msgCsend_message,    
  (tpl_base_sending_mo*)&msgMsend_message
};

#define OS_STOP_SEC_CONST_UNSPECIFIED
#include "tpl_memmap.h"
/*=============================================================================
 * Definition and initialization of Ready List structures
 */
#define OS_START_SEC_VAR_UNSPECIFIED
#include "tpl_memmap.h"

VAR(tpl_heap_entry, OS_VAR) tpl_ready_list[6];
VAR(tpl_rank_count, OS_VAR) tpl_tail_for_prio[6] = {
  0,
  0,
  0,
  0,
  0
};

#define OS_STOP_SEC_VAR_UNSPECIFIED
#include "tpl_memmap.h"

#define OS_START_SEC_VAR_UNSPECIFIED
#include "tpl_memmap.h"

/**
 * @internal
 *
 * tpl_kern gather informations on the current executing object and
 * the previous one
 */
VAR(tpl_kern_state, OS_VAR) tpl_kern =
{
  NULL,                      /* no running task static descriptor   */
  &IDLE_TASK_task_stat_desc, /* elected task to run is idle task    */
  NULL,                      /* no running task dynamic descriptor  */
  &IDLE_TASK_task_desc,      /* elected task to run is idle task    */
  INVALID_PROC_ID,           /* no running task so no ID            */
  INVALID_PROC_ID,           /* idle task has no ID                 */
  NO_NEED_SWITCH,            /* no context switch needed at start   */
  FALSE,                     /* no schedule needed at start         */
#if WITH_MEMORY_PROTECTION == YES
  1,                         /* at early system startup, we run in  */
                             /*  kernel mode, so in trusted mode    */
#endif /* WITH_MEMORY_PROTECTION */
};

#define OS_STOP_SEC_VAR_UNSPECIFIED
#include "tpl_memmap.h"

#define API_START_SEC_CONST_UNSPECIFIED
#include "tpl_memmap.h"
CONSTP2CONST(char, AUTOMATIC, OS_APPL_DATA) proc_name_table[TASK_COUNT + ISR_COUNT + 1] = {

  "TaskV",
  "TaskM",
  "TaskC",
  "stop",
  "*idle*"
};
#define API_STOP_SEC_CONST_UNSPECIFIED
#include "tpl_memmap.h"


/* End of file tpl_app_config.c */
