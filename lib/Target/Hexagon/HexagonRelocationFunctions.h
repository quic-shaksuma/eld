//===- HexagonRelocationFunctions.h----------------------------------------===//
// Part of the eld Project, under the BSD License
// See https://github.com/qualcomm/eld/LICENSE.txt for license information.
// SPDX-License-Identifier: BSD-3-Clause
//===----------------------------------------------------------------------===//

#ifndef HEXAGON_RELOCATION_FUNCTIONS_H
#define HEXAGON_RELOCATION_FUNCTIONS_H

#include "HexagonLLVMExtern.h"
#include "HexagonRelocator.h"

namespace eld {

class Relocation;

namespace {

struct RelocationDescription;

HexagonRelocator::Result none(Relocation &pEntry, HexagonRelocator &pParent,
                              RelocationDescription &RelocDesc);
HexagonRelocator::Result relocPCREL(Relocation &pEntry,
                                    HexagonRelocator &pParent,
                                    RelocationDescription &RelocDesc);
HexagonRelocator::Result relocGPREL(Relocation &pEntry,
                                    HexagonRelocator &pParent,
                                    RelocationDescription &RelocDesc);
HexagonRelocator::Result relocAbs(Relocation &pEntry, HexagonRelocator &pParent,
                                  RelocationDescription &RelocDesc);
HexagonRelocator::Result relocPLTB22PCREL(Relocation &pEntry,
                                          HexagonRelocator &pParent,
                                          RelocationDescription &RelocDesc);
HexagonRelocator::Result relocGOTREL(Relocation &pEntry,
                                     HexagonRelocator &pParent,
                                     RelocationDescription &RelocDesc);
HexagonRelocator::Result relocGOT(Relocation &pEntry, HexagonRelocator &pParent,
                                  RelocationDescription &RelocDesc);
HexagonRelocator::Result relocTPREL(Relocation &pEntry,
                                    HexagonRelocator &pParent,
                                    RelocationDescription &RelocDesc);
HexagonRelocator::Result relocDTPREL(Relocation &pEntry,
                                     HexagonRelocator &pParent,
                                     RelocationDescription &RelocDesc);
HexagonRelocator::Result relocIE(Relocation &pEntry, HexagonRelocator &pParent,
                                 RelocationDescription &RelocDesc);
HexagonRelocator::Result relocIEGOT(Relocation &pEntry,
                                    HexagonRelocator &pParent,
                                    RelocationDescription &RelocDesc);
HexagonRelocator::Result relocGDLDGOT(Relocation &pEntry,
                                      HexagonRelocator &pParent,
                                      RelocationDescription &RelocDesc);
HexagonRelocator::Result relocGDLDPLT(Relocation &pEntry,
                                      HexagonRelocator &pParent,
                                      RelocationDescription &RelocDesc);
HexagonRelocator::Result relocMsg(Relocation &pEntry, HexagonRelocator &pParent,
                                  RelocationDescription &RelocDesc);
HexagonRelocator::Result unsupport(Relocation &pEntry,
                                   HexagonRelocator &pParent,
                                   RelocationDescription &RelocDesc);

struct RelocationDescription;

typedef Relocator::Result (*ApplyFunctionType)(
    eld::Relocation &pReloc, eld::HexagonRelocator &pParent,
    RelocationDescription &pRelocDesc);

struct RelocationDescription {
  // The application function for the relocation.
  const ApplyFunctionType func;
  // The Relocation type, this is just kept for convenience when writing new
  // handlers for relocations.
  const unsigned int type;
  // If the user specified, the relocation to be force verified, the relocation
  // is verified for alignment, truncation errors(only for relocations that take
  // in non signed values, signed values are bound to exceed the number of
  // bits).
  bool forceVerify;
};

struct RelocationDescription RelocDesc[] = {
    {/*.func = */ none,
     /*.type = */ llvm::ELF::R_HEX_NONE,
     /*.forceVerify = */ false},
    {/*.func = */ &relocPCREL,
     /*.type = */ llvm::ELF::R_HEX_B22_PCREL,
     /*.forceVerify = */ false},
    {/*.func = */ &relocPCREL,
     /*.type = */ llvm::ELF::R_HEX_B15_PCREL,
     /*.forceVerify = */ false},
    {/*.func = */ &relocPCREL,
     /*.type = */ llvm::ELF::R_HEX_B7_PCREL,
     /*.forceVerify = */ false},
    {/*.func = */ &relocAbs,
     /*.type = */ llvm::ELF::R_HEX_LO16,
     /*.forceVerify = */ false},
    {/*.func = */ &relocAbs,
     /*.type = */ llvm::ELF::R_HEX_HI16,
     /*.forceVerify = */ false},
    {/*.func = */ &relocAbs,
     /*.type = */ llvm::ELF::R_HEX_32,
     /*.forceVerify = */ false},
    {/*.func = */ &relocAbs,
     /*.type = */ llvm::ELF::R_HEX_16,
     /*.forceVerify = */ false},
    {/*.func = */ &relocAbs,
     /*.type = */ llvm::ELF::R_HEX_8,
     /*.forceVerify = */ false},
    {/*.func = */ &relocGPREL,
     /*.type = */ llvm::ELF::R_HEX_GPREL16_0,
     /*.forceVerify = */ false},
    {/*.func = */ &relocGPREL,
     /*.type = */ llvm::ELF::R_HEX_GPREL16_1,
     /*.forceVerify = */ false},
    {/*.func = */ &relocGPREL,
     /*.type = */ llvm::ELF::R_HEX_GPREL16_2,
     /*.forceVerify = */ false},
    {/*.func = */ &relocGPREL,
     /*.type = */ llvm::ELF::R_HEX_GPREL16_3,
     /*.forceVerify = */ false},
    {/*.func = */ &unsupport,
     /*.type = */ llvm::ELF::R_HEX_HL16,
     /*.forceVerify = */ false},
    {/*.func = */ &relocPCREL,
     /*.type = */ llvm::ELF::R_HEX_B13_PCREL,
     /*.forceVerify = */ false},
    {/*.func = */ &relocPCREL,
     /*.type = */ llvm::ELF::R_HEX_B9_PCREL,
     /*.forceVerify = */ false},
    {/*.func = */ &relocPCREL,
     /*.type = */ llvm::ELF::R_HEX_B32_PCREL_X,
     /*.forceVerify = */ false},
    {/*.func = */ &relocAbs,
     /*.type = */ llvm::ELF::R_HEX_32_6_X,
     /*.forceVerify = */ false},
    {/*.func = */ &relocPCREL,
     /*.type = */ llvm::ELF::R_HEX_B22_PCREL_X,
     /*.forceVerify = */ false},
    {/*.func = */ &relocPCREL,
     /*.type = */ llvm::ELF::R_HEX_B15_PCREL_X,
     /*.forceVerify = */ false},
    {/*.func = */ &relocPCREL,
     /*.type = */ llvm::ELF::R_HEX_B13_PCREL_X,
     /*.forceVerify = */ false},
    {/*.func = */ &relocPCREL,
     /*.type = */ llvm::ELF::R_HEX_B9_PCREL_X,
     /*.forceVerify = */ false},
    {/*.func = */ &relocPCREL,
     /*.type = */ llvm::ELF::R_HEX_B7_PCREL_X,
     /*.forceVerify = */ false},
    {/*.func = */ &relocAbs,
     /*.type = */ llvm::ELF::R_HEX_16_X,
     /*.forceVerify = */ false},
    {/*.func = */ &relocAbs,
     /*.type = */ llvm::ELF::R_HEX_12_X,
     /*.forceVerify = */ false},
    {/*.func = */ &relocAbs,
     /*.type = */ llvm::ELF::R_HEX_11_X,
     /*.forceVerify = */ false},
    {/*.func = */ &relocAbs,
     /*.type = */ llvm::ELF::R_HEX_10_X,
     /*.forceVerify = */ false},
    {/*.func = */ &relocAbs,
     /*.type = */ llvm::ELF::R_HEX_9_X,
     /*.forceVerify = */ false},
    {/*.func = */ &relocAbs,
     /*.type = */ llvm::ELF::R_HEX_8_X,
     /*.forceVerify = */ false},
    {/*.func = */ &relocAbs,
     /*.type = */ llvm::ELF::R_HEX_7_X,
     /*.forceVerify = */ false},
    {/*.func = */ &relocAbs,
     /*.type = */ llvm::ELF::R_HEX_6_X,
     /*.forceVerify = */ false},
    {/*.func = */ &relocPCREL,
     /*.type = */ llvm::ELF::R_HEX_32_PCREL,
     /*.forceVerify = */ false},
    {/*.func = */ &none,
     /*.type = */ llvm::ELF::R_HEX_COPY,
     /*.forceVerify = */ false},
    {/*.func = */ &none,
     /*.type = */ llvm::ELF::R_HEX_GLOB_DAT,
     /*.forceVerify = */ false},
    {/*.func = */ &none,
     /*.type = */ llvm::ELF::R_HEX_JMP_SLOT,
     /*.forceVerify = */ false},
    {/*.func = */ &none,
     /*.type = */ llvm::ELF::R_HEX_RELATIVE,
     /*.forceVerify = */ false},
    {/*.func = */ &relocPLTB22PCREL,
     /*.type = */ llvm::ELF::R_HEX_PLT_B22_PCREL,
     /*.forceVerify = */ false},
    {/*.func = */ &relocGOTREL,
     /*.type = */ llvm::ELF::R_HEX_GOTREL_LO16,
     /*.forceVerify = */ false},
    {/*.func = */ &relocGOTREL,
     /*.type = */ llvm::ELF::R_HEX_GOTREL_HI16,
     /*.forceVerify = */ false},
    {/*.func = */ &relocGOTREL,
     /*.type = */ llvm::ELF::R_HEX_GOTREL_32,
     /*.forceVerify = */ false},
    {/*.func = */ &relocGOT,
     /*.type = */ llvm::ELF::R_HEX_GOT_LO16,
     /*.forceVerify = */ false},
    {/*.func = */ &relocGOT,
     /*.type = */ llvm::ELF::R_HEX_GOT_HI16,
     /*.forceVerify = */ false},
    {/*.func = */ &relocGOT,
     /*.type = */ llvm::ELF::R_HEX_GOT_32,
     /*.forceVerify = */ false},
    {/*.func = */ &relocGOT,
     /*.type = */ llvm::ELF::R_HEX_GOT_16,
     /*.forceVerify = */ false},
    {/*.func = */ &none,
     /*.type = */ llvm::ELF::R_HEX_DTPMOD_32,
     /*.forceVerify = */ false},
    {/*.func = */ &relocDTPREL,
     /*.type = */ llvm::ELF::R_HEX_DTPREL_LO16,
     /*.forceVerify = */ false},
    {/*.func = */ &relocDTPREL,
     /*.type = */ llvm::ELF::R_HEX_DTPREL_HI16,
     /*.forceVerify = */ false},
    {/*.func = */ &relocDTPREL,
     /*.type = */ llvm::ELF::R_HEX_DTPREL_32,
     /*.forceVerify = */ false},
    {/*.func = */ &relocDTPREL,
     /*.type = */ llvm::ELF::R_HEX_DTPREL_16,
     /*.forceVerify = */ false},
    {/*.func = */ &relocGDLDPLT,
     /*.type = */ llvm::ELF::R_HEX_GD_PLT_B22_PCREL,
     /*.forceVerify = */ false},
    {/*.func = */ &relocGDLDGOT,
     /*.type = */ llvm::ELF::R_HEX_GD_GOT_LO16,
     /*.forceVerify = */ false},
    {/*.func = */ &relocGDLDGOT,
     /*.type = */ llvm::ELF::R_HEX_GD_GOT_HI16,
     /*.forceVerify = */ false},
    {/*.func = */ &relocGDLDGOT,
     /*.type = */ llvm::ELF::R_HEX_GD_GOT_32,
     /*.forceVerify = */ false},
    {/*.func = */ &relocGDLDGOT,
     /*.type = */ llvm::ELF::R_HEX_GD_GOT_16,
     /*.forceVerify = */ false},
    {/*.func = */ &relocIE,
     /*.type = */ llvm::ELF::R_HEX_IE_LO16,
     /*.forceVerify = */ false},
    {/*.func = */ &relocIE,
     /*.type = */ llvm::ELF::R_HEX_IE_HI16,
     /*.forceVerify = */ false},
    {/*.func = */ &relocIE,
     /*.type = */ llvm::ELF::R_HEX_IE_32,
     /*.forceVerify = */ false},
    {/*.func = */ &relocIEGOT,
     /*.type = */ llvm::ELF::R_HEX_IE_GOT_LO16,
     /*.forceVerify = */ false},
    {/*.func = */ &relocIEGOT,
     /*.type = */ llvm::ELF::R_HEX_IE_GOT_HI16,
     /*.forceVerify = */ false},
    {/*.func = */ &relocIEGOT,
     /*.type = */ llvm::ELF::R_HEX_IE_GOT_32,
     /*.forceVerify = */ false},
    {/*.func = */ &relocIEGOT,
     /*.type = */ llvm::ELF::R_HEX_IE_GOT_16,
     /*.forceVerify = */ false},
    {/*.func = */ &relocTPREL,
     /*.type = */ llvm::ELF::R_HEX_TPREL_LO16,
     /*.forceVerify = */ false},
    {/*.func = */ &relocTPREL,
     /*.type = */ llvm::ELF::R_HEX_TPREL_HI16,
     /*.forceVerify = */ false},
    {/*.func = */ &relocTPREL,
     /*.type = */ llvm::ELF::R_HEX_TPREL_32,
     /*.forceVerify = */ false},
    {/*.func = */ &relocTPREL,
     /*.type = */ llvm::ELF::R_HEX_TPREL_16,
     /*.forceVerify = */ false},
    {/*.func = */ &relocPCREL,
     /*.type = */ llvm::ELF::R_HEX_6_PCREL_X,
     /*.forceVerify = */ false},
    {/*.func = */ &relocGOTREL,
     /*.type = */ llvm::ELF::R_HEX_GOTREL_32_6_X,
     /*.forceVerify = */ false},
    {/*.func = */ &relocGOTREL,
     /*.type = */ llvm::ELF::R_HEX_GOTREL_16_X,
     /*.forceVerify = */ false},
    {/*.func = */ &relocGOTREL,
     /*.type = */ llvm::ELF::R_HEX_GOTREL_11_X,
     /*.forceVerify = */ false},
    {/*.func = */ &relocGOT,
     /*.type = */ llvm::ELF::R_HEX_GOT_32_6_X,
     /*.forceVerify = */ false},
    {/*.func = */ &relocGOT,
     /*.type = */ llvm::ELF::R_HEX_GOT_16_X,
     /*.forceVerify = */ false},
    {/*.func = */ &relocGOT,
     /*.type = */ llvm::ELF::R_HEX_GOT_11_X,
     /*.forceVerify = */ false},
    {/*.func = */ &relocDTPREL,
     /*.type = */ llvm::ELF::R_HEX_DTPREL_32_6_X,
     /*.forceVerify = */ false},
    {/*.func = */ &relocDTPREL,
     /*.type = */ llvm::ELF::R_HEX_DTPREL_16_X,
     /*.forceVerify = */ false},
    {/*.func = */ &relocDTPREL,
     /*.type = */ llvm::ELF::R_HEX_DTPREL_11_X,
     /*.forceVerify = */ false},
    {/*.func = */ &relocGDLDGOT,
     /*.type = */ llvm::ELF::R_HEX_GD_GOT_32_6_X,
     /*.forceVerify = */ false},
    {/*.func = */ &relocGDLDGOT,
     /*.type = */ llvm::ELF::R_HEX_GD_GOT_16_X,
     /*.forceVerify = */ false},
    {/*.func = */ &relocGDLDGOT,
     /*.type = */ llvm::ELF::R_HEX_GD_GOT_11_X,
     /*.forceVerify = */ false},
    {/*.func = */ &relocIE,
     /*.type = */ llvm::ELF::R_HEX_IE_32_6_X,
     /*.forceVerify = */ false},
    {/*.func = */ &relocIE,
     /*.type = */ llvm::ELF::R_HEX_IE_16_X,
     /*.forceVerify = */ false},
    {/*.func = */ &relocIEGOT,
     /*.type = */ llvm::ELF::R_HEX_IE_GOT_32_6_X,
     /*.forceVerify = */ false},
    {/*.func = */ &relocIEGOT,
     /*.type = */ llvm::ELF::R_HEX_IE_GOT_16_X,
     /*.forceVerify = */ false},
    {/*.func = */ &relocIEGOT,
     /*.type = */ llvm::ELF::R_HEX_IE_GOT_11_X,
     /*.forceVerify = */ false},
    {/*.func = */ &relocTPREL,
     /*.type = */ llvm::ELF::R_HEX_TPREL_32_6_X,
     /*.forceVerify = */ false},
    {/*.func = */ &relocTPREL,
     /*.type = */ llvm::ELF::R_HEX_TPREL_16_X,
     /*.forceVerify = */ false},
    {/*.func = */ &relocTPREL,
     /*.type = */ llvm::ELF::R_HEX_TPREL_11_X,
     /*.forceVerify = */ false},
    {/*.func = */ &relocGDLDPLT,
     /*.type = */ llvm::ELF::R_HEX_LD_PLT_B22_PCREL,
     /*.forceVerify = */ false},
    {/*.func = */ &relocGDLDGOT,
     /*.type = */ llvm::ELF::R_HEX_LD_GOT_LO16,
     /*.forceVerify = */ false},
    {/*.func = */ &relocGDLDGOT,
     /*.type = */ llvm::ELF::R_HEX_LD_GOT_HI16,
     /*.forceVerify = */ false},
    {/*.func = */ &relocGDLDGOT,
     /*.type = */ llvm::ELF::R_HEX_LD_GOT_32,
     /*.forceVerify = */ false},
    {/*.func = */ &relocGDLDGOT,
     /*.type = */ llvm::ELF::R_HEX_LD_GOT_16,
     /*.forceVerify = */ false},
    {/*.func = */ &relocGDLDGOT,
     /*.type = */ llvm::ELF::R_HEX_LD_GOT_32_6_X,
     /*.forceVerify = */ false},
    {/*.func = */ &relocGDLDGOT,
     /*.type = */ llvm::ELF::R_HEX_LD_GOT_16_X,
     /*.forceVerify = */ false},
    {/*.func = */ &relocGDLDGOT,
     /*.type = */ llvm::ELF::R_HEX_LD_GOT_11_X,
     /*.forceVerify = */ false},
    {/*.func = */ &relocMsg,
     /*.type = */ llvm::ELF::R_HEX_23_REG,
     /*.forceVerify = */ false},
    {/*.func =*/&relocGDLDPLT,
     /*.type =*/llvm::ELF::R_HEX_GD_PLT_B22_PCREL_X,
     /*.forceVerify =*/false},
    {/*.func =*/&relocGDLDPLT,
     /*.type =*/llvm::ELF::R_HEX_GD_PLT_B32_PCREL_X,
     /*.forceVerify =*/false},
    {/*.func =*/&relocGDLDPLT,
     /*.type =*/llvm::ELF::R_HEX_LD_PLT_B22_PCREL_X,
     /*.forceVerify =*/false},
    {/*.func =*/&relocGDLDPLT,
     /*.type =*/llvm::ELF::R_HEX_LD_PLT_B32_PCREL_X,
     /*.forceVerify =*/false},
    {/*.func = */ &relocMsg,
     /*.type = */ llvm::ELF::R_HEX_27_REG,
     /*.forceVerify = */ false}};

#define HEXAGON_MAXRELOCS (llvm::ELF::R_HEX_27_REG + 1)

} // anonymous namespace

} // namespace eld

#endif // HEXAGON_RELOCATION_FUNCTIONS_H
