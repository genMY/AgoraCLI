#pragma once
#include "..\..\agorasdk\include\IAgoraRtcEngine.h"

using namespace agora::rtc;

namespace AgoraClrLibrary {
	//Native Function Pointer
	typedef void(__stdcall * PFOnJoinChannelSuccess)(const char* channel, const char* uid, int elapsed);
	typedef void(__stdcall * PFOnRejoinChannelSuccess)(const char* channel, const char* uid, int elapsed);
	typedef void(__stdcall * PFOnWarning)(int warn, const char* msg);
	typedef void(__stdcall * PFOnError)(int err, const char* msg);
	typedef void(__stdcall * PFOnAudioQuality)(const char* uid, int quality, unsigned short delay, unsigned short lost);
	typedef void(__stdcall * PFOnAudioVolumeIndication)(const agora::rtc::AudioVolumeInfo* speakers, unsigned int speakerNumber, int totalVolume);
	typedef void(__stdcall * PFOnLeaveChannel)(const agora::rtc::RtcStats& stats);
	typedef void(__stdcall * PFOnRtcStats)(const agora::rtc::RtcStats& stats);
	typedef void(__stdcall * PFOnAudioDeviceStateChanged)(const char* deviceId, int deviceType, int deviceState);
	typedef void(__stdcall * PFOnVideoDeviceStateChanged)(const char* deviceId, int deviceType, int deviceState);
	typedef void(__stdcall * PFOnLastmileQuality)(int quality);
	typedef void(__stdcall * PFOnNetworkQuality)(const char* uid, int txQuality, int rxQuality);
	typedef void(__stdcall * PFOnFirstLocalVideoFrame)(int width, int height, int elapsed);
	typedef void(__stdcall * PFOnFirstRemoteVideoDecoded)(const char* uid, int width, int height, int elapsed);
	typedef void(__stdcall * PFOnFirstRemoteVideoFrame)(const char* uid, int width, int height, int elapsed);
	typedef void(__stdcall * PFOnUserJoined)(const char* uid, int elapsed);
	typedef void(__stdcall * PFOnUserOffline)(const char* uid, USER_OFFLINE_REASON_TYPE reason);
	typedef void(__stdcall * PFOnUserMuteAudio)(const char* uid, bool muted);
	typedef void(__stdcall * PFOnUserMuteVideo)(const char* uid, bool muted);
	typedef void(__stdcall * PFOnUserEnableVideo)(const char* uid, bool enabled);
	typedef void(__stdcall * PFOnApiCallExecuted)(const char* api, int error);
	typedef void(__stdcall * PFOnLocalVideoStats)(const agora::rtc::LocalVideoStats& stats);
	typedef void(__stdcall * PFOnRemoteVideoStats)(const agora::rtc::RemoteVideoStats& stats);
	typedef void(__stdcall * PFOnCameraReady)();
	typedef void(__stdcall * PFOnVideoStopped)();
	typedef void(__stdcall * PFOnConnectionLost)();
	typedef void(__stdcall * PFOnConnectionInterrupted)();
	typedef void(__stdcall * PFOnRefreshRecordingServiceStatus)(int status);
	typedef void(__stdcall * PFOnStreamMessage)(const char* uid, int streamId, const char* data, size_t length);
	typedef void(__stdcall * PFOnStreamMessageError)(const char* uid, int streamId, int code, int missed, int cached);
	typedef void(__stdcall * PFOnRequestChannelKey)();
	typedef void(__stdcall * PFOnAudioMixingFinished)();
	typedef void(__stdcall * PFOnActiveSpeaker)(const char* uid);
	typedef void(__stdcall * PFOnClientRoleChanged)(CLIENT_ROLE_TYPE oldRole, CLIENT_ROLE_TYPE newRole);
	typedef void(__stdcall * PFOnAudioDeviceVolumeChanged)(MEDIA_DEVICE_TYPE, int, bool);

	//Native delegate	
	delegate void NativeOnJoinChannelSuccessDelegate(const char* channel, const char* uid, int elapsed);
	delegate void NativeOnRejoinChannelSuccessDelegate(const char* channel, const char* uid, int elapsed);
	delegate void NativeOnWarningDelegate(int warn, const char* msg);
	delegate void NativeOnErrorDelegate(int err, const char* msg);
	delegate void NativeOnAudioQualityDelegate(const char* uid, int quality, unsigned short delay, unsigned short lost);
	delegate void NativeOnAudioVolumeIndicationDelegate(const agora::rtc::AudioVolumeInfo* speakers, unsigned int speakerNumber, int totalVolume);
	delegate void NativeOnLeaveChannelDelegate(const agora::rtc::RtcStats& stats);
	delegate void NativeOnRtcStatsDelegate(const agora::rtc::RtcStats& stats);
	delegate void NativeOnAudioDeviceStateChangedDelegate(const char* deviceId, int deviceType, int deviceState);
	delegate void NativeOnVideoDeviceStateChangedDelegate(const char* deviceId, int deviceType, int deviceState);
	delegate void NativeOnLastmileQualityDelegate(int quality);
	delegate void NativeOnNetworkQualityDelegate(const char* uid, int txQuality, int rxQuality);
	delegate void NativeOnFirstLocalVideoFrameDelegate(int width, int height, int elapsed);
	delegate void NativeOnFirstRemoteVideoDecodedDelegate(const char* uid, int width, int height, int elapsed);
	delegate void NativeOnFirstRemoteVideoFrameDelegate(const char* uid, int width, int height, int elapsed);
	delegate void NativeOnUserJoinedDelegate(const char* uid, int elapsed);
	delegate void NativeOnUserOfflineDelegate(const char* uid, USER_OFFLINE_REASON_TYPE reason);
	delegate void NativeOnUserMuteAudioDelegate(const char* uid, bool muted);
	delegate void NativeOnUserMuteVideoDelegate(const char* uid, bool muted);
	delegate void NativeOnUserEnableVideoDelegate(const char* uid, bool enabled);
	delegate void NativeOnApiCallExecutedDelegate(const char* api, int error);
	delegate void NativeOnLocalVideoStatsDelegate(const agora::rtc::LocalVideoStats& stats);
	delegate void NativeOnRemoteVideoStatsDelegate(const agora::rtc::RemoteVideoStats& stats);
	delegate void NativeOnCameraReadyDelegate();
	delegate void NativeOnVideoStoppedDelegate();
	delegate void NativeOnConnectionLostDelegate();
	delegate void NativeOnConnectionInterruptedDelegate();
	delegate void NativeOnRefreshRecordingServiceStatusDelegate(int status);
	delegate void NativeOnStreamMessageDelegate(const char* uid, int streamId, const char* data, size_t length);
	delegate void NativeOnStreamMessageErrorDelegate(const char* uid, int streamId, int code, int missed, int cached);
	delegate void NativeOnRequestChannelKeyDelegate();
	delegate void NativeOnAudioMixingFinishedDelegate();
	delegate void NativeOnActiveSpeakerDelegate(const char* uid);
	delegate void NativeOnClientRoleChangedDelegate(CLIENT_ROLE_TYPE oldRole, CLIENT_ROLE_TYPE newRole);
	delegate void NativeOnAudioDeviceVolumeChangedDelegate(MEDIA_DEVICE_TYPE deviceType, int volume, bool muted);

	public class AgoraClrEventHandler : public agora::rtc::IRtcEngineEventHandler
	{
	public:
		AgoraClrEventHandler();
		~AgoraClrEventHandler();

		PFOnJoinChannelSuccess onJoinChannelSuccessEvent = 0;
		PFOnRejoinChannelSuccess onRejoinChannelSuccessEvent = 0;
		PFOnWarning onWarningEvent = 0;
		PFOnError onErrorEvent = 0;
		PFOnAudioQuality onAudioQualityEvent = 0;
		PFOnAudioVolumeIndication onAudioVolumeIndicationEvent = 0;
		PFOnLeaveChannel onLeaveChannelEvent = 0;
		PFOnRtcStats onRtcStatsEvent = 0;
		PFOnAudioDeviceStateChanged onAudioDeviceStateChangedEvent = 0;
		PFOnVideoDeviceStateChanged onVideoDeviceStateChangedEvent = 0;
		PFOnLastmileQuality onLastmileQualityEvent = 0;
		PFOnNetworkQuality onNetworkQualityEvent = 0;
		PFOnFirstLocalVideoFrame onFirstLocalVideoFrameEvent = 0;
		PFOnFirstRemoteVideoDecoded onFirstRemoteVideoDecodedEvent = 0;
		PFOnFirstRemoteVideoFrame onFirstRemoteVideoFrameEvent = 0;
		PFOnUserJoined onUserJoinedEvent = 0;
		PFOnUserOffline onUserOfflineEvent = 0;
		PFOnUserMuteAudio onUserMuteAudioEvent = 0;
		PFOnUserMuteVideo onUserMuteVideoEvent = 0;
		PFOnUserEnableVideo onUserEnableVideoEvent = 0;
		PFOnApiCallExecuted onApiCallExecutedEvent = 0;
		PFOnLocalVideoStats onLocalVideoStatsEvent = 0;
		PFOnRemoteVideoStats onRemoteVideoStatsEvent = 0;
		PFOnCameraReady onCameraReadyEvent = 0;
		PFOnVideoStopped onVideoStoppedEvent = 0;
		PFOnConnectionLost onConnectionLostEvent = 0;
		PFOnConnectionInterrupted onConnectionInterruptedEvent = 0;
		PFOnRefreshRecordingServiceStatus onRefreshRecordingServiceStatusEvent = 0;
		PFOnStreamMessage onStreamMessageEvent = 0;
		PFOnStreamMessageError onStreamMessageErrorEvent = 0;
		PFOnRequestChannelKey onRequestChannelKeyEvent = 0;
		PFOnAudioMixingFinished onAudioMixingFinishedEvent = 0;
		PFOnActiveSpeaker onActiveSpeakerEvent = 0;
		PFOnClientRoleChanged onClientRoleChangedEvent = 0;
		PFOnAudioDeviceVolumeChanged onAudioDeviceVolumeChangedEvent = 0;

		virtual void onJoinChannelSuccess(const char* channel, const char* uid, int elapsed);
		virtual void onRejoinChannelSuccess(const char* channel, const char* uid, int elapsed);
		virtual void onWarning(int warn, const char* msg);
		virtual void onError(int err, const char* msg);
		virtual void onAudioQuality(const char* uid, int quality, unsigned short delay, unsigned short lost);
		virtual void onAudioVolumeIndication(const agora::rtc::AudioVolumeInfo* speakers, unsigned int speakerNumber, int totalVolume);
		virtual void onLeaveChannel(const agora::rtc::RtcStats& stats);
		virtual void onRtcStats(const agora::rtc::RtcStats& stats);
		virtual void onAudioDeviceStateChanged(const char* deviceId, int deviceType, int deviceState);
		virtual void onVideoDeviceStateChanged(const char* deviceId, int deviceType, int deviceState);
		virtual void onLastmileQuality(int quality);
		virtual void onNetworkQuality(const char* uid, int txQuality, int rxQuality);
		virtual void onFirstLocalVideoFrame(int width, int height, int elapsed);
		virtual void onFirstRemoteVideoDecoded(const char* uid, int width, int height, int elapsed);
		virtual void onFirstRemoteVideoFrame(const char* uid, int width, int height, int elapsed);
		virtual void onUserJoined(const char* uid, int elapsed);
		virtual void onUserOffline(const char* uid, USER_OFFLINE_REASON_TYPE reason);
		virtual void onUserMuteAudio(const char* uid, bool muted);
		virtual void onUserMuteVideo(const char* uid, bool muted);
		virtual void onUserEnableVideo(const char* uid, bool enabled);
		virtual void onApiCallExecuted(const char* api, int error);
		virtual void onLocalVideoStats(const agora::rtc::LocalVideoStats& stats);
		virtual void onRemoteVideoStats(const agora::rtc::RemoteVideoStats& stats);
		virtual void onCameraReady();
		virtual void onVideoStopped();
		virtual void onConnectionLost();
		virtual void onConnectionInterrupted();
		virtual void onRefreshRecordingServiceStatus(int status);
		virtual void onStreamMessage(const char* uid, int streamId, const char* data, size_t length);
		virtual void onStreamMessageError(const char* uid, int streamId, int code, int missed, int cached);
		virtual void onRequestChannelKey();
		virtual void onAudioMixingFinished();
		virtual void onActiveSpeaker(const char* uid);
		virtual void onClientRoleChanged(CLIENT_ROLE_TYPE oldRole, CLIENT_ROLE_TYPE newRole);
		virtual void onAudioDeviceVolumeChanged(MEDIA_DEVICE_TYPE deviceType, int volume, bool muted);
	};

}