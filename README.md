# Disable BD PROCHOT UEFI extension
A small EFI executable for disabling BD(Bi-directional) PROCHOT upon boot.

BD PROCHOT causes CPU to lock on the lowest clock speed, if motherboard deems
certain parts are overheated(hence bi-directional).

If a thermal sensor on the motherboard is broken, BD PROCHOT can always be tripped.
If your motherboard is out of warranty, feel free to use this instead.

While modern PC setups are very safe from components overheating so extremely
to cause BD PROCHOT(it's mostly for extremely poorly maintained PCs),
I still hold no responsibilities from possible damages being caused to your PC.

## Why use this instead of ThrottleStop?
ThrottleStop is loaded after the OS has finished booting,
which means your entire OS loading is still done extremely slowly.

This doesn't mean ThrottleStop is no longer needed.
Please read below.

## Usage
This EFI executable must be loaded at the bootloader level.
Please use rEFInd or Clover.

Copying DisablePROCHOT.efi to drivers64UEFI directory is enough for Clover.

## Warning
Entering ACPI S3 state(suspend) causes the BD PROCHOT MSR bit getting re-enabled.
You need to use some userspace tool for disabling BD PROCHOT for such cases.

In case of Windows, use ThrottleStop.

In case of macOS, try [**SimpleMSR**](https://github.com/arter97/SimpleMSR)
