// Copyright (c) 2018 Park Ju Hyung

#include <efibind.h>
#include <efidef.h>
#include <efidevp.h>
#include <eficon.h>
#include <efiprot.h>
#include <efiapi.h>
#include <efierr.h>

static uint64_t AsmWriteMsr64(uint32_t index, uint64_t val)
{
	uint32_t low;
	uint32_t high;

	low  = (uint32_t)(val);
	high = (uint32_t)(val >> 32);

	__asm__ __volatile__ (
		"wrmsr"
		:
		: "c" (index),
		  "a" (low),
		  "d" (high)
	);

	return val;
}

EFI_STATUS
efi_main(EFI_HANDLE image, EFI_SYSTEM_TABLE *systemTable)
{
	SIMPLE_TEXT_OUTPUT_INTERFACE *conOut = systemTable->ConOut;
	conOut->OutputString(conOut, L"Disabling BD PROCHOT\r\n");

	AsmWriteMsr64(0x1FC, 0);

	conOut->OutputString(conOut, L"BD PROCHOT disabled\r\n");

	return EFI_SUCCESS;
}
