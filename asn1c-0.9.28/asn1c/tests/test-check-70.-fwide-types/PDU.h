/*
 * Generated by asn1c-0.9.28 (http://lionet.info/asn1c)
 * From ASN.1 module "ModuleTestXERDecoding"
 * 	found in "/home/intest/hozon/asnEDc/asn1c-0.9.28/tests/70-xer-test-OK.asn1"
 * 	`asn1c -S /home/intest/hozon/asnEDc/asn1c-0.9.28/skeletons -Wdebug-compiler -fwide-types`
 */

#ifndef	_PDU_H_
#define	_PDU_H_


#include <asn_application.h>

/* Including external dependencies */
#include "Sequence.h"
#include "Set.h"
#include "SequenceOf.h"
#include "ExtensibleSet.h"
#include "ExtensibleSequence.h"
#include "ExtensibleSequence2.h"
#include "SetOfNULL.h"
#include "SetOfREAL.h"
#include "SetOfEnums.h"
#include "NamedSetOfNULL.h"
#include "NamedSetOfREAL.h"
#include "NamedSetOfEnums.h"
#include "SeqOfZuka.h"
#include "SetOfChoice.h"
#include "NamedSetOfChoice.h"
#include <constr_CHOICE.h>

#ifdef __cplusplus
extern "C" {
#endif

/* Dependencies */
typedef enum PDU_PR {
	PDU_PR_NOTHING,	/* No components present */
	PDU_PR_sequence,
	PDU_PR_set,
	PDU_PR_sequenceOf,
	PDU_PR_extensibleSet,
	PDU_PR_extensibleSequence,
	PDU_PR_extensibleSequence2,
	PDU_PR_setOfNULL,
	PDU_PR_setOfREAL,
	PDU_PR_setOfEnums,
	PDU_PR_namedSetOfNULL,
	PDU_PR_namedSetOfREAL,
	PDU_PR_namedSetOfEnums,
	PDU_PR_seqOfZuka,
	PDU_PR_setOfChoice,
	PDU_PR_namedSetOfChoice,
	/* Extensions may appear below */
	
} PDU_PR;

/* PDU */
typedef struct PDU {
	PDU_PR present;
	union PDU_u {
		Sequence_t	 sequence;
		Set_t	 set;
		SequenceOf_t	 sequenceOf;
		ExtensibleSet_t	 extensibleSet;
		ExtensibleSequence_t	 extensibleSequence;
		ExtensibleSequence2_t	 extensibleSequence2;
		SetOfNULL_t	 setOfNULL;
		SetOfREAL_t	 setOfREAL;
		SetOfEnums_t	 setOfEnums;
		NamedSetOfNULL_t	 namedSetOfNULL;
		NamedSetOfREAL_t	 namedSetOfREAL;
		NamedSetOfEnums_t	 namedSetOfEnums;
		SeqOfZuka_t	 seqOfZuka;
		SetOfChoice_t	 setOfChoice;
		NamedSetOfChoice_t	 namedSetOfChoice;
		/*
		 * This type is extensible,
		 * possible extensions are below.
		 */
	} choice;
	
	/* Context for parsing across buffer boundaries */
	asn_struct_ctx_t _asn_ctx;
} PDU_t;

/* Implementation */
extern asn_TYPE_descriptor_t asn_DEF_PDU;

#ifdef __cplusplus
}
#endif

#endif	/* _PDU_H_ */
#include <asn_internal.h>