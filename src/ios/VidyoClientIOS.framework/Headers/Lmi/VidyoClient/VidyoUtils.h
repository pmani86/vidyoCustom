/**
{file:
	{name: VidyoUtils.h}
	{description: Device Utilities. }
	{copyright:
		(c) 2013-2016 Vidyo, Inc.,
		433 Hackensack Avenue,
		Hackensack, NJ  07601.

		All rights reserved.

		The information contained herein is proprietary to Vidyo, Inc.
		and shall not be reproduced, copied (in whole or in part), adapted,
		modified, disseminated, transmitted, transcribed, stored in a retrieval
		system, or translated into any language in any form by any means
		without the express written consent of Vidyo, Inc.
							***** CONFIDENTIAL *****
	}
}
*/

#ifndef VIDYO_UTILS_H_
#define VIDYO_UTILS_H_

#include <Lmi/Utils/LmiUtils.h>

LMI_BEGIN_EXTERN_C

char* GetTempDir(char* dir, LmiSizeT len);
LmiBool GetHardwareModel(char* model, int size);

LMI_END_EXTERN_C

#endif /* VIDYO_UTILS_H_ */
