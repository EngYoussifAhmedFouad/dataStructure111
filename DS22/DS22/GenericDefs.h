#pragma once

enum ORD_TYPE {
    ODG, ODN,   // Dine-in
    OT,         // Takeaway
    OVC, OVG, OVN // Delivery
};

enum CHEF_TYPE {
    CN, // Normal Chef
    CS  // Special Chef
};
enum Status {
	AVAILABLE,
	IN_SERVICE,
	IN_MAINTENANCE,
	BACK
};
