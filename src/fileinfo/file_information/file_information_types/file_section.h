/**
 * @file src/fileinfo/file_information/file_information_types/file_section.h
 * @brief Class for file section.
 * @copyright (c) 2017 Avast Software, licensed under the MIT license
 */

#ifndef FILEINFO_FILE_INFORMATION_FILE_INFORMATION_TYPES_FILE_SECTION_H
#define FILEINFO_FILE_INFORMATION_FILE_INFORMATION_TYPES_FILE_SECTION_H

#include "fileinfo/file_information/file_information_types/flags.h"

namespace retdec {
namespace fileinfo {

/**
 * Class for save information about section
 *
 * Value std::numeric_limits<unsigned long long>::max()/min() mean unspecified value or error for numeric types.
 */
class FileSection
{
	private:
		std::string sectionName;                  ///< name of section
		std::string sectionType;                  ///< type of section
		std::string crc32;                        ///< CRC32 of section content
		std::string md5;                          ///< MD5 of section content
		std::string sha256;                       ///< SHA256 of section content
		unsigned long long index = std::numeric_limits<unsigned long long>::max();                 ///< index of section
		unsigned long long offset = std::numeric_limits<unsigned long long>::max();                ///< offset in file
		unsigned long long sizeInFile = std::numeric_limits<unsigned long long>::max();            ///< size of section in file
		unsigned long long entrySize = std::numeric_limits<unsigned long long>::max();             ///< size of one entry in section
		unsigned long long startAddress = std::numeric_limits<unsigned long long>::max();          ///< start address in memory
		unsigned long long sizeInMemory = std::numeric_limits<unsigned long long>::max();          ///< size of section in memory
		unsigned long long relocationsOffset = std::numeric_limits<unsigned long long>::max();     ///< offset of relocation entries for this section
		unsigned long long numberOfRelocations = std::numeric_limits<unsigned long long>::max();   ///< number of relocation entries for this section
		unsigned long long lineNumbersOffset = std::numeric_limits<unsigned long long>::max();     ///< offset of line-number entries for this section
		unsigned long long numberOfLineNumbers = std::numeric_limits<unsigned long long>::max();   ///< number of line-number entries for this section
		unsigned long long memoryAlignment = std::numeric_limits<unsigned long long>::max();       ///< alignment in memory
		unsigned long long linkToSection = std::numeric_limits<unsigned long long>::max();         ///< link to another section
		unsigned long long extraInfo = std::numeric_limits<unsigned long long>::max();             ///< extra information about section
		unsigned long long lineOffset = std::numeric_limits<unsigned long long>::max();            ///< start line in file
		unsigned long long relocationsLineOffset = std::numeric_limits<unsigned long long>::max(); ///< start line of relocation entries for this section
		double entropy = std::numeric_limits<double>::min();                           ///< section data entropy
		Flags flags;                              ///< section flags
	public:
		/// @name Getters
		/// @{
		std::string getName() const;
		std::string getType() const;
		std::string getCrc32() const;
		std::string getMd5() const;
		std::string getSha256() const;
		std::string getIndexStr() const;
		std::string getOffsetStr(std::ios_base &(* format)(std::ios_base &)) const;
		std::string getSizeInFileStr(std::ios_base &(* format)(std::ios_base &)) const;
		std::string getEntrySizeStr(std::ios_base &(* format)(std::ios_base &)) const;
		std::string getStartAddressStr(std::ios_base &(* format)(std::ios_base &)) const;
		std::string getSizeInMemoryStr(std::ios_base &(* format)(std::ios_base &)) const;
		std::string getRelocationsOffsetStr(std::ios_base &(* format)(std::ios_base &)) const;
		std::string getNumberOfRelocationsStr() const;
		std::string getLineNumbersOffsetStr(std::ios_base &(* format)(std::ios_base &)) const;
		std::string getNumberOfLineNumbersStr() const;
		std::string getMemoryAlignmentStr(std::ios_base &(* format)(std::ios_base &)) const;
		std::string getLinkToAnotherSectionStr() const;
		std::string getExtraInfoStr() const;
		std::string getLineOffsetStr(std::ios_base &(* format)(std::ios_base &)) const;
		std::string getRelocationsLineOffsetStr(std::ios_base &(* format)(std::ios_base &)) const;
		std::string getEntropyStr(std::ios_base &(* format)(std::ios_base &)) const;
		unsigned long long getFlagsSize() const;
		unsigned long long getFlags() const;
		std::string getFlagsStr() const;
		std::size_t getNumberOfFlagsDescriptors() const;
		void getFlagsDescriptors(std::vector<std::string> &desc, std::vector<std::string> &abb) const;
		/// @}

		/// @name Setters
		/// @{
		void setName(std::string name);
		void setType(std::string type);
		void setCrc32(std::string sectionCrc32);
		void setMd5(std::string sectionMd5);
		void setSha256(std::string sectionSha256);
		void setIndex(unsigned long long sectionIndex);
		void setOffset(unsigned long long sectionOffset);
		void setSizeInFile(unsigned long long size);
		void setEntrySize(unsigned long long sizeOfOneEntry);
		void setStartAddress(unsigned long long memoryAddress);
		void setSizeInMemory(unsigned long long size);
		void setRelocationsOffset(unsigned long long relocOffset);
		void setNumberOfRelocations(unsigned long long relocations);
		void setLineNumbersOffset(unsigned long long lineNumOffset);
		void setNumberOfLineNumbers(unsigned long long lineNumbers);
		void setMemoryAlignment(unsigned long long alignment);
		void setLinkToAnotherSection(unsigned long long link);
		void setExtraInfo(unsigned long long extraInformation);
		void setLineOffset(unsigned long long sectionOffset);
		void setRelocationsLineOffset(unsigned long long relocOffset);
		void setEntropy(double entr);
		void setFlagsSize(unsigned long long flagsSize);
		void setFlags(unsigned long long flags);
		/// @}

		/// @name Other methods
		/// @{
		void addFlagsDescriptor(std::string descriptor, std::string abbreviation);
		void clearFlagsDescriptors();
		/// @}
};

} // namespace fileinfo
} // namespace retdec

#endif
