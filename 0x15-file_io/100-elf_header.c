#include <elf.h>
#include <stdio.h>
#include <stdlib.h>

/* ELF file magic number */
#define ELF_MAGIC "\x7fELF"

/* ELF class names */
static const char *elf_class_names[] = {
    "ELF32",
    "ELF64",
};

/* ELF data encoding names */
static const char *elf_data_encoding_names[] = {
    "2's complement, little endian",
    "2's complement, big endian",
};

/* ELF OS/ABI names */
static const char *elf_os_abi_names[] = {
    "UNIX - System V",
    "HP-UX",
    "NetBSD",
    "Linux",
    "Sun Solaris",
    "IBM AIX",
    "SGI Irix",
    "FreeBSD",
    "Compaq TRU64 UNIX",
    "Novell Modesto",
    "OpenBSD",
    "ARM",
    "Standalone (embedded)",
    "OpenVMS",
    "NonStop Kernel",
    "AROS",
    "Fuchsia",
    "PSOS",
    "EFI boot image",
    "Firmware",
    "Android",
    "Ceph",
    "AMX",
    "RISC-V",
};

void print_elf_header(const char *filename) {
  /* Open the ELF file. */
  FILE *elf_file = fopen(filename, "rb");
  if (elf_file == NULL) {
    perror("fopen");
    exit(EXIT_FAILURE);
  }

  /* Read the ELF header. */
  Elf64_Ehdr elf_header;
  if (fread(&elf_header, sizeof(elf_header), 1, elf_file) != 1) {
    perror("fread");
    exit(EXIT_FAILURE);
  }

  /* Check the ELF magic number. */
  if (memcmp(elf_header.e_ident, ELF_MAGIC, 4) != 0) {
    fprintf(stderr, "File '%s' is not an ELF file.\n", filename);
    exit(98);
  }

  /* Print the ELF header information. */
  printf("ELF Header:\n");
  printf("  Magic:   ");
  for (int i = 0; i < 4; i++) {
    printf("%02x ", elf_header.e_ident[i]);
  }
  printf("\n");
  printf("  Class:                             %s\n", elf_class_names[elf_header.e_ident[EI_CLASS]]);
  printf("  Data:                              %s\n", elf_data_encoding_names[elf_header.e_ident[EI_DATA]]);
  printf("  Version:                           %d (current)\n", elf_header.e_ident[EI_VERSION]);
  printf("  OS/ABI:                            %s\n", elf_os_abi_names[elf_header.e_ident[EI_OSABI]]);
  printf("  ABI Version:                       %d\n", elf_header.e_ident[EI_ABIVERSION]);
  printf("  Type:                              %d\n", elf_header.e_type);
  printf("  Entry point address:               0x%lx\n", elf_header.e_entry);

  /* Close the ELF file. */
  fclose(elf_file);
}

int main(int argc, char *argv[]) {
  if (argc != 2) {
    fprintf(stderr, "Usage: %s elf_filename\n", argv[0]);
    exit(EXIT_FAILURE);
  }

  print_elf_header(argv[1]);

  return EXIT_SUCCESS;
}
