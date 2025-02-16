DESCRIPTION = "Mainline Linux Kernel"
SECTION = "kernel"
LICENSE = "GPL-2.0-only"
LIC_FILES_CHKSUM = "file://${S}/COPYING;md5=bbea815ee2795b2f4230826c0c6b8814"

inherit kernel
require recipes-kernel/linux/linux-yocto.inc

LINUX_VERSION_EXTENSION = ""

PV = "${LINUX_VERSION}+git${SRCPV}"

KCONFIG_MODE="--alldefconfig"

KBUILD_DEFCONFIG:qemuriscv32 = "rv32_defconfig"
KBUILD_DEFCONFIG:qemuriscv64 = "defconfig"
KBUILD_DEFCONFIG:freedom-u540 = "defconfig"

COMPATIBLE_MACHINE = "(qemuriscv32|qemuriscv64|freedom-u540)"

KERNEL_DEVICETREE:freedom-u540 = "sifive/${RISCV_SBI_FDT}"

KERNEL_FEATURES:remove = "features/debug/printk.scc"
KERNEL_FEATURES:remove = "features/kernel-sample/kernel-sample.scc"
