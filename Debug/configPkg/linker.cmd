/*
 * Do not modify this file; it is automatically generated from the template
 * linkcmd.xdt in the ti.targets.elf package and will be overwritten.
 */

/*
 * put '"'s around paths because, without this, the linker
 * considers '-' as minus operator, not a file name character.
 */


-l"E:\Studio\TICCS\mcip_master\Debug\configPkg\package\cfg\mcip_master_pe66.oe66"
-l"D:\Program\Texas\MCSDK\ipc_1_24_03_32\packages\ti\sdo\ipc\lib\instrumented_e66\ipc\ipc.lib"
-l"D:\Program\Texas\MCSDK\ndk_2_24_03_35\packages\ti\ndk\hal\timer_bios\lib\hal_timer_bios.ae66"
-l"D:\Program\Texas\MCSDK\ndk_2_24_03_35\packages\ti\ndk\os\lib\os.ae66"
-l"D:\Program\Texas\MCSDK\ndk_2_24_03_35\packages\ti\ndk\hal\userled_stub\lib\hal_userled_stub.ae66"
-l"D:\Program\Texas\MCSDK\ndk_2_24_03_35\packages\ti\ndk\hal\eth_stub\lib\hal_eth_stub.ae66"
-l"D:\Program\Texas\MCSDK\ndk_2_24_03_35\packages\ti\ndk\tools\cgi\lib\cgi.ae66"
-l"D:\Program\Texas\MCSDK\ndk_2_24_03_35\packages\ti\ndk\tools\hdlc\lib\hdlc.ae66"
-l"D:\Program\Texas\MCSDK\ndk_2_24_03_35\packages\ti\ndk\tools\console\lib\console_min_ipv4.ae66"
-l"D:\Program\Texas\MCSDK\ndk_2_24_03_35\packages\ti\ndk\netctrl\lib\netctrl_ipv4.ae66"
-l"D:\Program\Texas\MCSDK\ndk_2_24_03_35\packages\ti\ndk\nettools\lib\nettool_ipv4.ae66"
-l"D:\Program\Texas\MCSDK\ndk_2_24_03_35\packages\ti\ndk\hal\ser_stub\lib\hal_ser_stub.ae66"
-l"D:\Program\Texas\MCSDK\ndk_2_24_03_35\packages\ti\ndk\tools\servers\lib\servers_min_ipv4.ae66"
-l"D:\Program\Texas\MCSDK\ndk_2_24_03_35\packages\ti\ndk\stack\lib\stk_ppp_pppoe.ae66"
-l"D:\Program\Texas\MCSDK\pdk_C6678_1_1_2_6\packages\ti\transport\ndk\nimu\lib\debug\ti.transport.ndk.nimu.ae66"
-l"D:\Program\Texas\MCSDK\pdk_C6678_1_1_2_6\packages\ti\platform\evmc6678l\platform_lib\lib\debug\ti.platform.evm6678l.ae66"
-l"D:\Program\Texas\MCSDK\pdk_C6678_1_1_2_6\packages\ti\drv\cppi\lib\ti.drv.cppi.ae66"
-l"D:\Program\Texas\MCSDK\pdk_C6678_1_1_2_6\packages\ti\drv\qmss\lib\ti.drv.qmss.ae66"
-l"D:\Program\Texas\MCSDK\pdk_C6678_1_1_2_6\packages\ti\drv\pa\lib\ti.drv.pa.ae66"
-l"D:\Program\Texas\MCSDK\pdk_C6678_1_1_2_6\packages\ti\csl\lib\ti.csl.ae66"
-l"D:\Program\Texas\MCSDK\bios_6_33_06_50\packages\ti\sysbios\lib\instrumented_e66\sysbios\sysbios.lib"
-l"D:\Program\Texas\MCSDK\xdctools_3_23_04_60\packages\ti\targets\rts6000\lib\ti.targets.rts6000.ae66"
-l"D:\Program\Texas\MCSDK\xdctools_3_23_04_60\packages\ti\targets\rts6000\lib\boot.ae66"

--retain="*(xdc.meta)"


--args 0x0
-heap  0x0
-stack 0x1000

MEMORY
{
    L2SRAM (RWX) : org = 0x800000, len = 0x40000
    MSMCSRAM_MASTER (RWX) : org = 0xc000000, len = 0x100000
    MSMCSRAM_SLAVE (RWX) : org = 0xc100000, len = 0x100000
    MSMCSRAM_IPC (RWX) : org = 0xc200000, len = 0x200000
    DDR3 (RWX) : org = 0x80000000, len = 0x10000000
}

/*
 * Linker command file contributions from all loaded packages:
 */

/* Content from xdc.services.global (null): */

/* Content from xdc (null): */

/* Content from xdc.corevers (null): */

/* Content from xdc.shelf (null): */

/* Content from xdc.services.spec (null): */

/* Content from xdc.services.intern.xsr (null): */

/* Content from xdc.services.intern.gen (null): */

/* Content from xdc.services.intern.cmd (null): */

/* Content from xdc.bld (null): */

/* Content from ti.targets (null): */

/* Content from ti.targets.elf (null): */

/* Content from xdc.rov (null): */

/* Content from xdc.runtime (null): */

/* Content from ti.targets.rts6000 (null): */

/* Content from ti.sysbios.interfaces (null): */

/* Content from ti.sysbios.family (null): */

/* Content from xdc.services.getset (null): */

/* Content from ti.ndk.rov (null): */

/* Content from ti.sysbios (null): */

/* Content from ti.sysbios.hal (null): */

/* Content from ti.sysbios.knl (null): */

/* Content from ti.sysbios.family.c66 (null): */

/* Content from ti.sysbios.family.c64p (null): */

/* Content from ti.csl (null): */

/* Content from ti.drv.pa (null): */

/* Content from ti.drv.qmss (null): */

/* Content from ti.drv.cppi (null): */

/* Content from ti.platform.evmc6678l (null): */

/* Content from ti.transport.ndk (null): */

/* Content from ti.sysbios.gates (null): */

/* Content from ti.sysbios.heaps (null): */

/* Content from xdc.runtime.knl (null): */

/* Content from ti.sdo.ipc.interfaces (null): */

/* Content from ti.sysbios.syncs (null): */

/* Content from ti.sdo.ipc.family (null): */

/* Content from ti.sdo.utils (null): */

/* Content from ti.sysbios.utils (null): */

/* Content from ti.sysbios.xdcruntime (null): */

/* Content from ti.sysbios.family.c62 (null): */

/* Content from ti.sysbios.timers.timer64 (null): */

/* Content from ti.sysbios.family.c64p.tci6488 (null): */

/* Content from ti.ndk (null): */

/* Content from ti.ndk.hal.timer_bios (null): */

/* Content from ti.ndk.os (null): */

/* Content from ti.ndk.hal.userled_stub (null): */

/* Content from ti.ndk.hal.eth_stub (null): */

/* Content from ti.ndk.tools.cgi (null): */

/* Content from ti.ndk.tools.hdlc (null): */

/* Content from ti.ndk.stack (null): */

/* Content from ti.ndk.tools.console (null): */

/* Content from ti.ndk.netctrl (null): */

/* Content from ti.ndk.nettools (null): */

/* Content from ti.ndk.hal.ser_stub (null): */

/* Content from ti.ndk.tools.servers (null): */

/* Content from ti.ndk.config (null): */

/* Content from ti.catalog.c6000 (null): */

/* Content from ti.catalog (null): */

/* Content from ti.catalog.peripherals.hdvicp2 (null): */

/* Content from xdc.platform (null): */

/* Content from xdc.cfg (null): */

/* Content from ti.platforms.generic (null): */

/* Content from demos.image_processing.ipc.evmc6678l.platform (null): */

/* Content from ti.sdo.ipc.heaps (null): */

/* Content from ti.sdo.ipc (ti/sdo/ipc/linkcmd.xdt): */

SECTIONS
{
    ti.sdo.ipc.SharedRegion_0:  { . += 0x200000;} run > 0xc200000, type = NOLOAD
}


/* Content from ti.sdo.ipc.family.c647x (null): */

/* Content from ti.sdo.ipc.notifyDrivers (null): */

/* Content from ti.sdo.ipc.transports (null): */

/* Content from ti.sdo.ipc.nsremote (null): */

/* Content from ti.sdo.ipc.gates (null): */

/* Content from configPkg (null): */


/*
 * symbolic aliases for static instance objects
 */
xdc_runtime_Startup__EXECFXN__C = 1;
xdc_runtime_Startup__RESETFXN__C = 1;
TSK_idle = ti_sysbios_knl_Task_Object__table__V + 72;

SECTIONS
{
    .text: load >> MSMCSRAM_MASTER
    .ti.decompress: load > L2SRAM
    .stack: load > L2SRAM
    GROUP: load > L2SRAM
    {
        .bss:
        .neardata:
        .rodata:
    }
    .cinit: load > MSMCSRAM_MASTER
    .pinit: load >> L2SRAM
    .init_array: load > L2SRAM
    .const: load >> MSMCSRAM_MASTER
    .data: load >> L2SRAM
    .fardata: load >> L2SRAM
    .switch: load >> MSMCSRAM_MASTER align = 0x8
    .sysmem: load > L2SRAM
    .far: load >> L2SRAM
    .args: load > L2SRAM align = 0x4, fill = 0 {_argsize = 0x0; }
    .cio: load >> L2SRAM align = 0x8
    .ti.handler_table: load > L2SRAM
    .vecs: load >> MSMCSRAM_MASTER align = 0x400
    .cppi: load >> L2SRAM align = 0x10
    .qmss: load >> L2SRAM align = 0x10
    .nimu_eth_ll2: load >> L2SRAM align = 0x10
    .far:NDK_PACKETMEM: load >> MSMCSRAM_MASTER align = 0x80
    .far:NDK_OBJMEM: load >> MSMCSRAM_MASTER align = 0x10
    .resmgr_memregion: load >> L2SRAM align = 0x80
    .resmgr_handles: load >> L2SRAM align = 0x10
    .resmgr_pa: load >> L2SRAM align = 0x8
    systemHeapMaster: load >> DDR3
    .code: load >> L2SRAM
    .defaultStackSection: load >> L2SRAM
    .plt: load >> L2SRAM
    platform_lib: load >> L2SRAM
    xdc.meta: load >> MSMCSRAM_MASTER, type = COPY

}
