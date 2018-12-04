//
//	VidyoConnector_Objc.h
//	VidyoClient
//
//	This file is auto generated, do not edit this file
//	Copyright (c) 2016 Vidyo, Inc. All rights reserved.
//

#import "VidyoAudioFrame_Objc.h"
#import "VidyoChatMessage_Objc.h"
#import "VidyoDevice_Objc.h"
#import "VidyoLocalCamera_Objc.h"
#import "VidyoLocalMicrophone_Objc.h"
#import "VidyoLocalMonitor_Objc.h"
#import "VidyoLocalSpeaker_Objc.h"
#import "VidyoLocalWindowShare_Objc.h"
#import "VidyoLogRecord_Objc.h"
#import "VidyoNetworkInterface_Objc.h"
#import "VidyoParticipant_Objc.h"
#import "VidyoRemoteCamera_Objc.h"
#import "VidyoRemoteMicrophone_Objc.h"
#import "VidyoRemoteWindowShare_Objc.h"
#import "VidyoVideoFrame_Objc.h"
typedef NS_ENUM(NSInteger, VCConnectorBaseTransportType){
	VCConnectorBaseTransportTypeTLS,
	VCConnectorBaseTransportTypeTCP,
	VCConnectorBaseTransportTypeUDP
};
typedef NS_ENUM(NSInteger, VCConnectorDisconnectReason){
	VCConnectorDisconnectReasonDisconnected,
	VCConnectorDisconnectReasonConnectionLost,
	VCConnectorDisconnectReasonConnectionTimeout,
	VCConnectorDisconnectReasonNoResponse,
	VCConnectorDisconnectReasonTerminated,
	VCConnectorDisconnectReasonMiscLocalError,
	VCConnectorDisconnectReasonMiscRemoteError,
	VCConnectorDisconnectReasonMiscError
};
typedef NS_ENUM(NSInteger, VCConnectorFailReason){
	VCConnectorFailReasonConnectionFailed,
	VCConnectorFailReasonConnectionLost,
	VCConnectorFailReasonConnectionTimeout,
	VCConnectorFailReasonNoResponse,
	VCConnectorFailReasonTerminated,
	VCConnectorFailReasonInvalidToken,
	VCConnectorFailReasonUnableToCreateResource,
	VCConnectorFailReasonNoResponseFromResource,
	VCConnectorFailReasonInvalidResourceId,
	VCConnectorFailReasonResourceFull,
	VCConnectorFailReasonNotMember,
	VCConnectorFailReasonBanned,
	VCConnectorFailReasonMediaNotEnabled,
	VCConnectorFailReasonMediaFailed,
	VCConnectorFailReasonMiscLocalError,
	VCConnectorFailReasonMiscRemoteError,
	VCConnectorFailReasonMiscError
};
typedef NS_ENUM(NSInteger, VCConnectorMode){
	VCConnectorModeDefault,
	VCConnectorModeForeground,
	VCConnectorModeBackground
};
typedef NS_ENUM(NSInteger, VCConnectorState){
	VCConnectorStateIdle,
	VCConnectorStateReady,
	VCConnectorStateEstablishingConnection,
	VCConnectorStateFindingResource,
	VCConnectorStateConnectingToResource,
	VCConnectorStateEnablingMedia,
	VCConnectorStateConnected
};
typedef NS_ENUM(NSInteger, VCConnectorTradeOffProfile){
	VCConnectorTradeOffProfileHigh,
	VCConnectorTradeOffProfileMedium,
	VCConnectorTradeOffProfileLow
};
typedef NS_ENUM(NSInteger, VCConnectorViewStyle){
	VCConnectorViewStyleDefault,
	VCConnectorViewStyleTiles
};
@interface VCConnectorPkg : NSObject
{}

	+(BOOL) vcInitialize;
	+(BOOL) setExperimentalOptions:(const char*)options;
	+(void) uninitialize;
@end
@protocol VCConnectorIConnect

	-(void) onSuccess;
	-(void) onFailure:(VCConnectorFailReason)reason;
	-(void) onDisconnected:(VCConnectorDisconnectReason)reason;
@end
@protocol VCConnectorIRegisterLocalCameraEventListener

	-(void) onLocalCameraAdded:(VCLocalCamera*)localCamera;
	-(void) onLocalCameraRemoved:(VCLocalCamera*)localCamera;
	-(void) onLocalCameraSelected:(VCLocalCamera*)localCamera;
	-(void) onLocalCameraStateUpdated:(VCLocalCamera*)localCamera State:(VCDeviceState)state;
@end
@protocol VCConnectorIRegisterLocalCameraFrameListener

	-(void) onLocalCameraFrame:(VCLocalCamera*)localCamera VideoFrame:(VCVideoFrame*)videoFrame;
@end
@protocol VCConnectorIRegisterLocalMicrophoneEnergyListener

	-(void) onLocalMicrophoneEnergy:(VCLocalMicrophone*)localMicrophone AudioEnergy:(int)audioEnergy;
@end
@protocol VCConnectorIRegisterLocalMicrophoneEventListener

	-(void) onLocalMicrophoneAdded:(VCLocalMicrophone*)localMicrophone;
	-(void) onLocalMicrophoneRemoved:(VCLocalMicrophone*)localMicrophone;
	-(void) onLocalMicrophoneSelected:(VCLocalMicrophone*)localMicrophone;
	-(void) onLocalMicrophoneStateUpdated:(VCLocalMicrophone*)localMicrophone State:(VCDeviceState)state;
@end
@protocol VCConnectorIRegisterLocalMicrophoneFrameListener

	-(void) onLocalMicrophoneFrame:(VCLocalMicrophone*)localMicrophone AudioFrame:(VCAudioFrame*)audioFrame;
@end
@protocol VCConnectorIRegisterLocalMonitorEventListener

	-(void) onLocalMonitorAdded:(VCLocalMonitor*)localMonitor;
	-(void) onLocalMonitorRemoved:(VCLocalMonitor*)localMonitor;
	-(void) onLocalMonitorSelected:(VCLocalMonitor*)localMonitor;
	-(void) onLocalMonitorStateUpdated:(VCLocalMonitor*)localMonitor State:(VCDeviceState)state;
@end
@protocol VCConnectorIRegisterLocalMonitorFrameListener

	-(void) onLocalMonitorFrame:(VCLocalMonitor*)localMonitor VideoFrame:(VCVideoFrame*)videoFrame;
@end
@protocol VCConnectorIRegisterLocalSpeakerEventListener

	-(void) onLocalSpeakerAdded:(VCLocalSpeaker*)localSpeaker;
	-(void) onLocalSpeakerRemoved:(VCLocalSpeaker*)localSpeaker;
	-(void) onLocalSpeakerSelected:(VCLocalSpeaker*)localSpeaker;
	-(void) onLocalSpeakerStateUpdated:(VCLocalSpeaker*)localSpeaker State:(VCDeviceState)state;
@end
@protocol VCConnectorIRegisterLocalWindowShareEventListener

	-(void) onLocalWindowShareAdded:(VCLocalWindowShare*)localWindowShare;
	-(void) onLocalWindowShareRemoved:(VCLocalWindowShare*)localWindowShare;
	-(void) onLocalWindowShareSelected:(VCLocalWindowShare*)localWindowShare;
	-(void) onLocalWindowShareStateUpdated:(VCLocalWindowShare*)localWindowShare State:(VCDeviceState)state;
@end
@protocol VCConnectorIRegisterLocalWindowShareFrameListener

	-(void) onLocalWindowShareFrame:(VCLocalWindowShare*)localWindowShare VideoFrame:(VCVideoFrame*)videoFrame;
@end
@protocol VCConnectorIRegisterLogEventListener

	-(void) onLog:(VCLogRecord*)logRecord;
@end
@protocol VCConnectorIRegisterMessageEventListener

	-(void) onChatMessageReceived:(VCParticipant*)participant ChatMessage:(VCChatMessage*)chatMessage;
@end
@protocol VCConnectorIRegisterNetworkInterfaceEventListener

	-(void) onNetworkInterfaceAdded:(VCNetworkInterface*)networkInterface;
	-(void) onNetworkInterfaceRemoved:(VCNetworkInterface*)networkInterface;
	-(void) onNetworkInterfaceSelected:(VCNetworkInterface*)networkInterface TransportType:(VCNetworkInterfaceTransportType)transportType;
	-(void) onNetworkInterfaceStateUpdated:(VCNetworkInterface*)networkInterface State:(VCNetworkInterfaceState)state;
@end
@protocol VCConnectorIRegisterParticipantEventListener

	-(void) onParticipantJoined:(VCParticipant*)participant;
	-(void) onParticipantLeft:(VCParticipant*)participant;
	-(void) onDynamicParticipantChanged:(NSMutableArray*)participants;
	-(void) onLoudestParticipantChanged:(VCParticipant*)participant AudioOnly:(BOOL)audioOnly;
@end
@protocol VCConnectorIRegisterRecorderInCallEventListener

	-(void) recorderInCall:(BOOL)recorderInCall;
@end
@protocol VCConnectorIRegisterRemoteCameraEventListener

	-(void) onRemoteCameraAdded:(VCRemoteCamera*)remoteCamera Participant:(VCParticipant*)participant;
	-(void) onRemoteCameraRemoved:(VCRemoteCamera*)remoteCamera Participant:(VCParticipant*)participant;
	-(void) onRemoteCameraStateUpdated:(VCRemoteCamera*)remoteCamera Participant:(VCParticipant*)participant State:(VCDeviceState)state;
@end
@protocol VCConnectorIRegisterRemoteCameraFrameListener

	-(void) onRemoteCameraFrame:(VCRemoteCamera*)remoteCamera Participant:(VCParticipant*)participant VideoFrame:(VCVideoFrame*)videoFrame;
@end
@protocol VCConnectorIRegisterRemoteMicrophoneEnergyListener

	-(void) onRemoteMicrophoneEnergy:(VCRemoteMicrophone*)remoteMicrophone Participant:(VCParticipant*)participant AudioEnergy:(int)audioEnergy;
@end
@protocol VCConnectorIRegisterRemoteMicrophoneEventListener

	-(void) onRemoteMicrophoneAdded:(VCRemoteMicrophone*)remoteMicrophone Participant:(VCParticipant*)participant;
	-(void) onRemoteMicrophoneRemoved:(VCRemoteMicrophone*)remoteMicrophone Participant:(VCParticipant*)participant;
	-(void) onRemoteMicrophoneStateUpdated:(VCRemoteMicrophone*)remoteMicrophone Participant:(VCParticipant*)participant State:(VCDeviceState)state;
@end
@protocol VCConnectorIRegisterRemoteMicrophoneFrameListener

	-(void) onRemoteMicrophoneFrame:(VCRemoteMicrophone*)remoteMicrophone Participant:(VCParticipant*)participant AudioFrame:(VCAudioFrame*)audioFrame;
@end
@protocol VCConnectorIRegisterRemoteWindowShareEventListener

	-(void) onRemoteWindowShareAdded:(VCRemoteWindowShare*)remoteWindowShare Participant:(VCParticipant*)participant;
	-(void) onRemoteWindowShareRemoved:(VCRemoteWindowShare*)remoteWindowShare Participant:(VCParticipant*)participant;
	-(void) onRemoteWindowShareStateUpdated:(VCRemoteWindowShare*)remoteWindowShare Participant:(VCParticipant*)participant State:(VCDeviceState)state;
@end
@protocol VCConnectorIRegisterRemoteWindowShareFrameListener

	-(void) onRemoteWindowShareFrame:(VCRemoteWindowShare*)remoteWindowShare Participant:(VCParticipant*)participant VideoFrame:(VCVideoFrame*)videoFrame;
@end
@protocol VCConnectorIRegisterResourceManagerEventListener

	-(void) onAvailableResourcesChanged:(unsigned int)cpuEncode CpuDecode:(unsigned int)cpuDecode BandwidthSend:(unsigned int)bandwidthSend BandwidthReceive:(unsigned int)bandwidthReceive;
	-(void) onMaxRemoteSourcesChanged:(unsigned int)maxRemoteSources;
@end
@protocol VCConnectorIRegisterWebProxyEventListener

	-(void) onWebProxyCredentialsRequest:(NSMutableString*)webProxyAddress;
@end
@interface VCConnector : NSObject
{
	void* objPtr;
	@public
	id<VCConnectorIConnect> connectorIConnect;
	id<VCConnectorIRegisterLocalCameraEventListener> connectorIRegisterLocalCameraEventListener;
	id<VCConnectorIRegisterLocalCameraFrameListener> connectorIRegisterLocalCameraFrameListener;
	id<VCConnectorIRegisterLocalMicrophoneEnergyListener> connectorIRegisterLocalMicrophoneEnergyListener;
	id<VCConnectorIRegisterLocalMicrophoneEventListener> connectorIRegisterLocalMicrophoneEventListener;
	id<VCConnectorIRegisterLocalMicrophoneFrameListener> connectorIRegisterLocalMicrophoneFrameListener;
	id<VCConnectorIRegisterLocalMonitorEventListener> connectorIRegisterLocalMonitorEventListener;
	id<VCConnectorIRegisterLocalMonitorFrameListener> connectorIRegisterLocalMonitorFrameListener;
	id<VCConnectorIRegisterLocalSpeakerEventListener> connectorIRegisterLocalSpeakerEventListener;
	id<VCConnectorIRegisterLocalWindowShareEventListener> connectorIRegisterLocalWindowShareEventListener;
	id<VCConnectorIRegisterLocalWindowShareFrameListener> connectorIRegisterLocalWindowShareFrameListener;
	id<VCConnectorIRegisterLogEventListener> connectorIRegisterLogEventListener;
	id<VCConnectorIRegisterMessageEventListener> connectorIRegisterMessageEventListener;
	id<VCConnectorIRegisterNetworkInterfaceEventListener> connectorIRegisterNetworkInterfaceEventListener;
	id<VCConnectorIRegisterParticipantEventListener> connectorIRegisterParticipantEventListener;
	id<VCConnectorIRegisterRecorderInCallEventListener> connectorIRegisterRecorderInCallEventListener;
	id<VCConnectorIRegisterRemoteCameraEventListener> connectorIRegisterRemoteCameraEventListener;
	id<VCConnectorIRegisterRemoteCameraFrameListener> connectorIRegisterRemoteCameraFrameListener;
	id<VCConnectorIRegisterRemoteMicrophoneEnergyListener> connectorIRegisterRemoteMicrophoneEnergyListener;
	id<VCConnectorIRegisterRemoteMicrophoneEventListener> connectorIRegisterRemoteMicrophoneEventListener;
	id<VCConnectorIRegisterRemoteMicrophoneFrameListener> connectorIRegisterRemoteMicrophoneFrameListener;
	id<VCConnectorIRegisterRemoteWindowShareEventListener> connectorIRegisterRemoteWindowShareEventListener;
	id<VCConnectorIRegisterRemoteWindowShareFrameListener> connectorIRegisterRemoteWindowShareFrameListener;
	id<VCConnectorIRegisterResourceManagerEventListener> connectorIRegisterResourceManagerEventListener;
	id<VCConnectorIRegisterWebProxyEventListener> connectorIRegisterWebProxyEventListener;
}

	-(id) init:(void*)viewId ViewStyle:(VCConnectorViewStyle)viewStyle RemoteParticipants:(unsigned int)remoteParticipants LogFileFilter:(const char*)logFileFilter LogFileName:(const char*)logFileName UserData:(long)userData;
	-(void) dealloc;
	-(BOOL) assignViewToCompositeRenderer:(void*)viewId ViewStyle:(VCConnectorViewStyle)viewStyle RemoteParticipants:(unsigned int)remoteParticipants;
	-(BOOL) assignViewToLocalCamera:(void*)viewId LocalCamera:(VCLocalCamera*)localCamera DisplayCropped:(BOOL)displayCropped AllowZoom:(BOOL)allowZoom;
	-(BOOL) assignViewToLocalMonitor:(void*)viewId LocalMonitor:(VCLocalMonitor*)localMonitor DisplayCropped:(BOOL)displayCropped AllowZoom:(BOOL)allowZoom;
	-(BOOL) assignViewToLocalWindowShare:(void*)viewId LocalWindowShare:(VCLocalWindowShare*)localWindowShare DisplayCropped:(BOOL)displayCropped AllowZoom:(BOOL)allowZoom;
	-(BOOL) assignViewToRemoteCamera:(void*)viewId RemoteCamera:(VCRemoteCamera*)remoteCamera DisplayCropped:(BOOL)displayCropped AllowZoom:(BOOL)allowZoom;
	-(BOOL) assignViewToRemoteWindowShare:(void*)viewId RemoteWindowShare:(VCRemoteWindowShare*)remoteWindowShare DisplayCropped:(BOOL)displayCropped AllowZoom:(BOOL)allowZoom;
	-(BOOL) connect:(const char*)host Token:(const char*)token DisplayName:(const char*)displayName ResourceId:(const char*)resourceId ConnectorIConnect:(id<VCConnectorIConnect>)connectorIConnect;
	-(BOOL) connectToRoomAsGuest:(const char*)host DisplayName:(const char*)displayName RoomKey:(const char*)roomKey ConnectorIConnect:(id<VCConnectorIConnect>)connectorIConnect;
	-(BOOL) connectToRoomWithId:(const char*)host UserName:(const char*)userName Password:(const char*)password RoomId:(const char*)roomId ConnectorIConnect:(id<VCConnectorIConnect>)connectorIConnect;
	-(BOOL) connectToRoomWithKey:(const char*)host UserName:(const char*)userName Password:(const char*)password RoomKey:(const char*)roomKey ConnectorIConnect:(id<VCConnectorIConnect>)connectorIConnect;
	-(BOOL) connectToRoomWithTokenAndId:(const char*)host UserName:(const char*)userName Token:(const char*)token RoomId:(const char*)roomId ConnectorIConnect:(id<VCConnectorIConnect>)connectorIConnect;
	-(BOOL) connectToRoomWithTokenAndKey:(const char*)host UserName:(const char*)userName Token:(const char*)token RoomKey:(const char*)roomKey ConnectorIConnect:(id<VCConnectorIConnect>)connectorIConnect;
	-(BOOL) cycleCamera;
	-(BOOL) cycleMicrophone;
	-(BOOL) cycleSpeaker;
	-(void) disable;
	-(void) disableDebug;
	-(void) disconnect;
	-(BOOL) enableDebug:(unsigned int)port LogFilter:(const char*)logFilter;
	-(VCConnectorTradeOffProfile) getCpuTradeOffProfile;
	-(VCConnectorState) getState;
	-(NSString*) getStatsJson;
	-(NSString*) getVersion;
	-(NSString*) getVersionWithoutBuildNumber;
	-(BOOL) hideView:(void*)viewId;
	-(BOOL) registerLocalCameraEventListener:(id<VCConnectorIRegisterLocalCameraEventListener>)connectorIRegisterLocalCameraEventListener;
	-(BOOL) registerLocalCameraFrameListener:(id<VCConnectorIRegisterLocalCameraFrameListener>)connectorIRegisterLocalCameraFrameListener LocalCamera:(VCLocalCamera*)localCamera Width:(unsigned int)width Height:(unsigned int)height FrameInterval:(long)frameInterval;
	-(BOOL) registerLocalMicrophoneEnergyListener:(id<VCConnectorIRegisterLocalMicrophoneEnergyListener>)connectorIRegisterLocalMicrophoneEnergyListener;
	-(BOOL) registerLocalMicrophoneEventListener:(id<VCConnectorIRegisterLocalMicrophoneEventListener>)connectorIRegisterLocalMicrophoneEventListener;
	-(BOOL) registerLocalMicrophoneFrameListener:(id<VCConnectorIRegisterLocalMicrophoneFrameListener>)connectorIRegisterLocalMicrophoneFrameListener LocalMicrophone:(VCLocalMicrophone*)localMicrophone;
	-(BOOL) registerLocalMonitorEventListener:(id<VCConnectorIRegisterLocalMonitorEventListener>)connectorIRegisterLocalMonitorEventListener;
	-(BOOL) registerLocalMonitorFrameListener:(id<VCConnectorIRegisterLocalMonitorFrameListener>)connectorIRegisterLocalMonitorFrameListener LocalMonitor:(VCLocalMonitor*)localMonitor Width:(unsigned int)width Height:(unsigned int)height FrameInterval:(long)frameInterval;
	-(BOOL) registerLocalSpeakerEventListener:(id<VCConnectorIRegisterLocalSpeakerEventListener>)connectorIRegisterLocalSpeakerEventListener;
	-(BOOL) registerLocalWindowShareEventListener:(id<VCConnectorIRegisterLocalWindowShareEventListener>)connectorIRegisterLocalWindowShareEventListener;
	-(BOOL) registerLocalWindowShareFrameListener:(id<VCConnectorIRegisterLocalWindowShareFrameListener>)connectorIRegisterLocalWindowShareFrameListener LocalWindowShare:(VCLocalWindowShare*)localWindowShare Width:(unsigned int)width Height:(unsigned int)height FrameInterval:(long)frameInterval;
	-(BOOL) registerLogEventListener:(id<VCConnectorIRegisterLogEventListener>)connectorIRegisterLogEventListener Filter:(const char*)filter;
	-(BOOL) registerMessageEventListener:(id<VCConnectorIRegisterMessageEventListener>)connectorIRegisterMessageEventListener;
	-(BOOL) registerNetworkInterfaceEventListener:(id<VCConnectorIRegisterNetworkInterfaceEventListener>)connectorIRegisterNetworkInterfaceEventListener;
	-(BOOL) registerParticipantEventListener:(id<VCConnectorIRegisterParticipantEventListener>)connectorIRegisterParticipantEventListener;
	-(BOOL) registerRecorderInCallEventListener:(id<VCConnectorIRegisterRecorderInCallEventListener>)connectorIRegisterRecorderInCallEventListener;
	-(BOOL) registerRemoteCameraEventListener:(id<VCConnectorIRegisterRemoteCameraEventListener>)connectorIRegisterRemoteCameraEventListener;
	-(BOOL) registerRemoteCameraFrameListener:(id<VCConnectorIRegisterRemoteCameraFrameListener>)connectorIRegisterRemoteCameraFrameListener RemoteCamera:(VCRemoteCamera*)remoteCamera Width:(unsigned int)width Height:(unsigned int)height FrameInterval:(long)frameInterval;
	-(BOOL) registerRemoteMicrophoneEnergyListener:(id<VCConnectorIRegisterRemoteMicrophoneEnergyListener>)connectorIRegisterRemoteMicrophoneEnergyListener;
	-(BOOL) registerRemoteMicrophoneEventListener:(id<VCConnectorIRegisterRemoteMicrophoneEventListener>)connectorIRegisterRemoteMicrophoneEventListener;
	-(BOOL) registerRemoteMicrophoneFrameListener:(id<VCConnectorIRegisterRemoteMicrophoneFrameListener>)connectorIRegisterRemoteMicrophoneFrameListener RemoteMicrophone:(VCRemoteMicrophone*)remoteMicrophone;
	-(BOOL) registerRemoteWindowShareEventListener:(id<VCConnectorIRegisterRemoteWindowShareEventListener>)connectorIRegisterRemoteWindowShareEventListener;
	-(BOOL) registerRemoteWindowShareFrameListener:(id<VCConnectorIRegisterRemoteWindowShareFrameListener>)connectorIRegisterRemoteWindowShareFrameListener RemoteWindowShare:(VCRemoteWindowShare*)remoteWindowShare Width:(unsigned int)width Height:(unsigned int)height FrameInterval:(long)frameInterval;
	-(BOOL) registerResourceManagerEventListener:(id<VCConnectorIRegisterResourceManagerEventListener>)connectorIRegisterResourceManagerEventListener;
	-(BOOL) registerWebProxyEventListener:(id<VCConnectorIRegisterWebProxyEventListener>)connectorIRegisterWebProxyEventListener;
	-(BOOL) selectAudioContentShare:(VCLocalMicrophone*)localMicrophone;
	-(BOOL) selectDefaultCamera;
	-(BOOL) selectDefaultMicrophone;
	-(BOOL) selectDefaultNetworkInterfaceForMedia;
	-(BOOL) selectDefaultNetworkInterfaceForSignaling;
	-(BOOL) selectDefaultSpeaker;
	-(BOOL) selectLocalCamera:(VCLocalCamera*)localCamera;
	-(BOOL) selectLocalMicrophone:(VCLocalMicrophone*)localMicrophone;
	-(BOOL) selectLocalMonitor:(VCLocalMonitor*)localMonitor;
	-(BOOL) selectLocalSpeaker:(VCLocalSpeaker*)localSpeaker;
	-(BOOL) selectLocalWindowShare:(VCLocalWindowShare*)localWindowShare;
	-(BOOL) selectNetworkInterfaceForMedia:(VCNetworkInterface*)networkInterface;
	-(BOOL) selectNetworkInterfaceForSignaling:(VCNetworkInterface*)networkInterface;
	-(BOOL) selectVideoContentShare:(VCLocalCamera*)localCamera;
	-(BOOL) sendChatMessage:(const char*)message;
	-(BOOL) setAdvancedOptions:(const char*)options;
	-(BOOL) setCameraNudgeConfiguration:(const char*)cameraNudgeConfig;
	-(BOOL) setCameraPrivacy:(BOOL)privacy;
	-(void) setCertificateAuthorityList:(const char*)certificateAuthorityList;
	-(BOOL) setCpuTradeOffProfile:(VCConnectorTradeOffProfile)profile;
	-(BOOL) setLocation:(double)latitude Longitude:(double)longitude;
	-(void) setMaxBitRate:(unsigned int)bitRate;
	-(BOOL) setMicrophonePrivacy:(BOOL)privacy;
	-(BOOL) setMode:(VCConnectorMode)mode;
	-(BOOL) setPool:(const char*)name;
	-(BOOL) setSpeakerPrivacy:(BOOL)privacy;
	-(BOOL) setTCPTransport:(BOOL)enable;
	-(BOOL) setTURNAddressCredentials:(const char*)turnAddress Port:(unsigned int)port Username:(const char*)username Password:(const char*)password BaseTransport:(VCConnectorBaseTransportType)baseTransport;
	-(BOOL) setTURNServerCertificateRequired:(BOOL)required;
	-(BOOL) setUDPTransport:(BOOL)enable;
	-(BOOL) setViewAnimationSpeed:(void*)viewId SpeedPercentage:(unsigned int)speedPercentage;
	-(BOOL) setViewBackgroundColor:(void*)viewId Red:(unsigned char)red Green:(unsigned char)green Blue:(unsigned char)blue;
	-(void) setWebProxyAddressCredentials:(const char*)proxyAddress Username:(const char*)username Password:(const char*)password;
	-(BOOL) setWebProxyTransport:(BOOL)enable;
	-(BOOL) showAudioMeters:(void*)viewId ShowMeters:(BOOL)showMeters;
	-(BOOL) showPreview:(BOOL)preview;
	-(BOOL) showViewAt:(void*)viewId X:(int)x Y:(int)y Width:(unsigned int)width Height:(unsigned int)height;
	-(BOOL) showViewLabel:(void*)viewId ShowLabel:(BOOL)showLabel;
	-(BOOL) showWindowSharePreview:(BOOL)preview;
	-(BOOL) unregisterLocalCameraEventListener;
	-(BOOL) unregisterLocalCameraFrameListener:(VCLocalCamera*)localCamera;
	-(BOOL) unregisterLocalMicrophoneEnergyListener;
	-(BOOL) unregisterLocalMicrophoneEventListener;
	-(BOOL) unregisterLocalMicrophoneFrameListener:(VCLocalMicrophone*)localMicrophone;
	-(BOOL) unregisterLocalMonitorEventListener;
	-(BOOL) unregisterLocalMonitorFrameListener:(VCLocalMonitor*)localMonitor;
	-(BOOL) unregisterLocalSpeakerEventListener;
	-(BOOL) unregisterLocalWindowShareEventListener;
	-(BOOL) unregisterLocalWindowShareFrameListener:(VCLocalWindowShare*)localWindowShare;
	-(BOOL) unregisterLogEventListener;
	-(BOOL) unregisterMessageEventListener;
	-(BOOL) unregisterNetworkInterfaceEventListener;
	-(BOOL) unregisterParticipantEventListener;
	-(BOOL) unregisterRecorderInCallEventListener;
	-(BOOL) unregisterRemoteCameraEventListener;
	-(BOOL) unregisterRemoteCameraFrameListener:(VCRemoteCamera*)remoteCamera;
	-(BOOL) unregisterRemoteMicrophoneEnergyListener;
	-(BOOL) unregisterRemoteMicrophoneEventListener;
	-(BOOL) unregisterRemoteMicrophoneFrameListener:(VCRemoteMicrophone*)remoteMicrophone;
	-(BOOL) unregisterRemoteWindowShareEventListener;
	-(BOOL) unregisterRemoteWindowShareFrameListener:(VCRemoteWindowShare*)remoteWindowShare;
	-(BOOL) unregisterResourceManagerEventListener;
	-(BOOL) unregisterWebProxyEventListener;
	-(id) initWithObject:(void*)rPtr;
	-(void*)getObjectPtr;
@end
