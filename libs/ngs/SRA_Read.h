/*===========================================================================
*
*                            PUBLIC DOMAIN NOTICE
*               National Center for Biotechnology Information
*
*  This software/database is a "United States Government Work" under the
*  terms of the United States Copyright Act.  It was written as part of
*  the author's official duties as a United States Government employee and
*  thus cannot be copyrighted.  This software/database is freely available
*  to the public for use. The National Library of Medicine and the U.S.
*  Government have not placed any restriction on its use or reproduction.
*
*  Although all reasonable efforts have been taken to ensure the accuracy
*  and reliability of the software and data, the NLM and the U.S.
*  Government do not and cannot warrant the performance or results that
*  may be obtained by using this software or data. The NLM and the U.S.
*  Government disclaim all warranties, express or implied, including
*  warranties of performance, merchantability or fitness for any particular
*  purpose.
*
*  Please cite the author in any work or product based on this material.
*
* ===========================================================================
*
*/

#ifndef _h_sra_read_
#define _h_sra_read_

typedef struct SRA_Read SRA_Read;
#ifndef _h_ngs_read_
#define NGS_READ SRA_Read
#include "NGS_Read.h"
#endif

#ifdef __cplusplus
extern "C" {
#endif

/*--------------------------------------------------------------------------
 * forwards
 */
struct NGS_Cursor;
struct NGS_String;

enum SequenceTableColumn
{
    seq_READ_TYPE,
    seq_READ,
    seq_QUALITY_ASCII,
    seq_QUALITY,
    seq_READ_LEN,
    seq_NAME,
    seq_GROUP,
    seq_PRIMARY_ALIGNMENT_ID,
    seq_SPOT_COUNT,

    seq_NUM_COLS
};

extern const char * sequence_col_specs [];

/*--------------------------------------------------------------------------
 * SRA_Read
 */

/* Make
 * a single read
 */
struct NGS_Read * SRA_ReadMake ( ctx_t ctx, const struct NGS_Cursor * curs, int64_t readId, const struct NGS_String * spec );

/* IteratorMake
 */
struct NGS_Read * SRA_ReadIteratorMake ( ctx_t ctx, 
                                               const struct NGS_Cursor * curs, 
                                               const struct NGS_String * run_name, 
                                               bool wants_full, 
                                               bool wants_partial, 
                                               bool wants_unaligned );

/* IteratorMakeRange
 * all reads in the specified range of rowIds
 */
struct NGS_Read * SRA_ReadIteratorMakeRange ( ctx_t ctx, 
                                              const struct NGS_Cursor * curs, 
                                              const struct NGS_String * run_name, 
                                              uint64_t first, 
                                              uint64_t count, 
                                              bool wants_full, 
                                              bool wants_partial, 
                                              bool wants_unaligned );

/* IteratorMakeReadGroup
 * within the specified range of rowIds, will only return reads belonging to the specified read group (groupName)
 */
struct NGS_Read * SRA_ReadIteratorMakeReadGroup ( ctx_t ctx, 
                                                  const struct NGS_Cursor * curs, 
                                                  const struct NGS_String * run_name, 
                                                  const struct NGS_String * group_name, 
                                                  uint64_t first, 
                                                  uint64_t count, 
                                                  bool wants_full, 
                                                  bool wants_partial, 
                                                  bool wants_unaligned );

#ifdef __cplusplus
}
#endif

#endif /* _h_sra_read_ */
