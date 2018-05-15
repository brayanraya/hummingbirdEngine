#ifndef _alarmableManager
#define _alarmableManager

#include <map>

class alarmable;

////////////////////////////////////////////////////////////////////////////////////////////////////
/// <summary>	Manager for alarmables. </summary>
///
/// <remarks>	Braya, 3/1/2017. </remarks>
////////////////////////////////////////////////////////////////////////////////////////////////////
class alarmableManager
{	
public:

	////////////////////////////////////////////////////////////////////////////////////////////////////
	/// <summary>	Values that represent alarm numbers. </summary>
	///
	/// <remarks>	Braya, 3/1/2017. </remarks>
	////////////////////////////////////////////////////////////////////////////////////////////////////
	enum class ALARM_ID: char
	{
		ALARM0,
		ALARM1,
		ALARM2,
		ALARM3,
	};
	static const int ALARM_NUMBER = 4;
	using AlarmEvent = std::pair<alarmable*, ALARM_ID>;
	using TimeLineMap = std::multimap<float, AlarmEvent>;

private:
	TimeLineMap alarmableManagerList;

friend class scene;
	////////////////////////////////////////////////////////////////////////////////////////////////////
	/// <summary>	Process the elements. </summary>
	///
	/// <remarks>	Braya, 3/1/2017. </remarks>
	////////////////////////////////////////////////////////////////////////////////////////////////////
	void processElements();

public:
	alarmableManager() {};
	~alarmableManager();
	
	alarmableManager(const alarmableManager&) = delete;
	alarmableManager& operator=(const alarmableManager&) = delete;

	////////////////////////////////////////////////////////////////////////////////////////////////////
	/// <summary>	Registers the alarmable. </summary>
	///
	/// <remarks>	Braya, 3/1/2017. </remarks>
	///
	/// <param name="time">   	The time. </param>
	/// <param name="inEvent">	The in event. </param>
	////////////////////////////////////////////////////////////////////////////////////////////////////
	void registerAlarmable(float time, AlarmEvent inEvent);

	////////////////////////////////////////////////////////////////////////////////////////////////////
	/// <summary>	Deregisters the alarmable. </summary>
	///
	/// <remarks>	Braya, 3/1/2017. </remarks>
	///
	/// <param name="alarm">	[in,out] If non-null, the alarm. </param>
	/// <param name="id">   	The identifier. </param>
	////////////////////////////////////////////////////////////////////////////////////////////////////
	void deregisterAlarmable(alarmable * alarm, ALARM_ID id);

	using alarmableMapRef = TimeLineMap::iterator;
};

#endif //!_alarmableManager