/*
 * Machine Generated include file for message "Laser Designate Msg".
 * NOTE: This file is read only. DO NOT ATTEMPT TO MODIFY IT BY HAND.
 * Generated on 17-March-1998 at 22:13:19
 * Generated from file EVENTS.XLS by Microprose
 */

#ifndef _LASERDESIGNATEMSG_H
#define _LASERDESIGNATEMSG_H

/*
 * Required Include Files
 */
#include "F4vu.h"
#include "FalcMesg.h"
#include "mission.h"

#pragma pack (1)

/*
 * Message Type Laser Designate Msg
 */
class FalconLaserDesignateMsg : public FalconEvent
{
   public:
      FalconLaserDesignateMsg(VU_ID entityId, VuTargetEntity *target, VU_BOOL loopback=TRUE);
      FalconLaserDesignateMsg(VU_MSG_TYPE type, VU_ID senderid, VU_ID target);
      ~FalconLaserDesignateMsg(void);
      int Size (void) { return sizeof(dataBlock) + FalconEvent::Size();};
      int Decode (VU_BYTE **buf, int length)
         {
         int size;

            size = FalconEvent::Decode (buf, length);
            memcpy (&dataBlock, *buf, sizeof (dataBlock));
            *buf += sizeof (dataBlock);
            size += sizeof (dataBlock);
            return size;
         };
      int Encode (VU_BYTE **buf)
         {
         int size;

            size = FalconEvent::Encode (buf);
            memcpy (*buf, &dataBlock, sizeof (dataBlock));
            *buf += sizeof (dataBlock);
            size += sizeof (dataBlock);
            return size;
         };
      class DATA_BLOCK
      {
         public:
            VU_ID source;
            VU_ID target;
            uchar state;
      } dataBlock;

   protected:
      int Process(uchar autodisp);
};
#pragma pack ()

#endif
