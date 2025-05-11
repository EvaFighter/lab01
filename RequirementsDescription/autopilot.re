As a driver, I want to activate autonomous driving mode, so that vehicle can operate safely without manual control
{
Basic Flow {
	(User) 1. the Driver shall start vehicle and select a destination.
	(User) 2. the Driver shall activate autonomous driving mode.
	(System) 3. When autonomous mode is activated, the APS shall initialize sensors and perform environmental scanning.
	(System) 4. the APS shall calculate a safe route based on current traffic and road conditions.
	(System) 5. the APS shall control steering and acceleration and braking to navigate toward destination.
	}
Alternative Flow {
	A. At any time, system fails :
		To support safety and recovery and  ensure all sensor data and vehicle state and decision history can be restored or safely reset from any point in driving scenario.
			1. Driver takes over control manually or system initiates safe stop procedure.
			2. System attempts to restore latest stable driving state from logs and memory.
				a2. System detects inconsistencies or sensor failure preventing recovery.
					1. System alerts driver and records diagnostics and transitions to fallback driving mode or enters minimal risk condition.
}
}

As a driver, I want to take over control at any time during autonomous driving, so that I can respond to unexpected situations manually
{
Basic Flow {
	(User) 1. the Driver shall activate autonomous driving mode.
	(System) 2. When autonomous mode is activated, the APS shall take over control of vehicle.
	(User) 3. the Driver shall indicate intent to take over .
	(System) 4. the APS shall smoothly transfer control back to driver.
	(System) 5. the APS shall log handover event and deactivate autonomous mode.
}

Alternative Flow {
	A. At any time, driver takes over suddenly without prior signal :
		To support smooth transition and ensure safety during emergency takeover that system must detect driver input and hand over control immediately with minimal risk.
			1. The system detects unexpected manual input.
			2. The APS immediately deactivates autonomous mode and grants full control to driver.
			3. The system logs event and optionally provides auditory or visual feedback confirming manual control.
	}
}

As a driver, I want to activate automatic parking mode, so that  vehicle can park itself safely and accurately
{
Basic Flow {
	(User) 1. the Driver shall bring vehicle to a suitable parking area and stop.
	(User) 2. the Driver shall activate automatic parking mode.
	(System) 3. When parking mode is activated, the APS shall scan for available parking spaces.
	(System) 4. the APS shall select a suitable space and calculate parking trajectory.
	(System) 5. the APS shall control steering and acceleration and braking to park vehicle.
	(System) 6. the APS shall notify driver upon successful parking and deactivate parking mode.
}

Alternative Flow {
	A. At any time, parking process is interrupted or fails :
		To support safety and user confidence that ensure system can gracefully abort parking and return control or retry as appropriate.
			1. The APS detects unexpected obstacle or inaccurate positioning.
			2. The APS halts parking process and alerts driver.
			3. The Driver should choose to retry parking or take over control manually.
			4. The APS should log interruption event and transition to safe state.
	}
}

As a driver, I want to let system automatically optimize driving route, so that I can reach my destination faster and more efficiently
{
Basic Flow {
	(User) 1. the Driver shall input or confirm destination.
	(System) 2. When destination is set, the APS shall generate an initial driving route.
	(System) 3. the APS shall continuously monitor traffic and road conditions and navigation data.
	(System) 4. the APS shall detect opportunities to optimize route in realtime.
	(System) 5. the APS shall update route and notify driver of new plan.
	(System) 6. the APS shall follow optimized route to navigate toward destination.
}

Alternative Flow {
	A. At any time, route optimization is not possible or rejected by driver :
		To support flexibility and user control that system should  ensure that original route is preserved and driver consent is respected.
			1. The APS fails to find a better route or traffic data is unavailable.
			2. The APS continues to follow original route and logs event.
				a2. The Driver rejects suggested optimized route.
					1. The APS cancels route change and continues with current plan.
}
}

As a driver, I want to switch from manual driving to autonomous driving at any time, so that I can reduce driving effort at time that conditions allow
{
Basic Flow {
	(User) 1. the Driver shall manually operate vehicle.
	(User) 2. the Driver shall activate autonomous driving mode during driving.
	(System) 3. When autonomous mode is activated, the APS shall evaluate environmental conditions and vehicle status.
	(System) 4. the APS shall confirm safety conditions are met for autonomous driving.
	(System) 5. the APS shall take over control and notify driver of successful transition.
	(System) 6. the APS shall continue driving according to selected destination or current route.
}

Alternative Flow {
	A. At any time, activation conditions are not met :
		To ensure safety and prevent inappropriate activation that system must validate all requirements before transition.
			1. The APS detects unsafe conditions like poor visibility and unmapped area and sensor fault.
			2. The APS should reject  activation request and notify driver with reason.
			3. The APS should remain in manual mode and log failed activation attempt.
}
}