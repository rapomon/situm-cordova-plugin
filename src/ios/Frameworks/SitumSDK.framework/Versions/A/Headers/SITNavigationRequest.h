//
//  SITNavigationRequest.h
//  SitumSDK
//
//  Created by A Barros on 22/3/17.
//  Copyright © 2017 Situm. All rights reserved.
//

#ifndef SITNavigationRequest_h
#define SITNavigationRequest_h

#import <Foundation/Foundation.h>

#import "SITRoute.h"

/**
 Class that stores relevant information to request navigation updates.
 */
@interface SITNavigationRequest : NSObject

/**
 Distance in meters at which will be consider that the user has arrived to the destination of a route
 
 @discussion The minimum value for this parameter is 3 meters and maximum is 15 meters. Default value is 10 meters.
 */
@property (nonatomic) NSInteger distanceToGoalThreshold;

/**
 Distance in meters at which the Navigation Component should consider that the user is outside a route and it's recommended to recompute a new one.
 
 @return distance in meters.
 @discussion The minimum value is 3 meters and maximum is 15 meters. Default value is 9 meters.
 */
@property (nonatomic) NSInteger outsideRouteThreshold;

/**
 Distance in meters at which will be consider that the user has arrived to a change floor indication
 
@return distance in meters.
 @discussion Default value is 10 meters.
 */
@property (nonatomic) NSInteger distanceToFloorChangeThreshold;

/**
 Distance in meters at which will be consider that the user has arrived to the next indication
 
 @return distance in meters.
 @discussion Default value is 5 meters.
 */
@property (nonatomic) NSInteger distanceToChangeIndicationThreshold;

/**
 SITRoute object considered to navigate
 */
@property (nonatomic, strong) SITRoute *route;

/**
 Initialize a request to navigate through a route

 @param route the route (returned by SITDirectionManager) you want to navigate
 @return initialized request
 @discussion this request will have default values for the distanceToGoalThreshold and outsideRouteThreshold.
 */
- (instancetype)initWithRoute:(SITRoute *)route;

/**
 Set a threshold within which the next indication will be returned
 
 @param distanceToChangeIndicationThreshold distance to change indication threshold
 */
-(void)setDistanceToChangeIndicationThreshold:(NSInteger)distanceToChangeIndicationThreshold;

/**
 Set a threshold within which the next change floor indication will be returned
 
 @param distanceToChangeFloorThreshold distance to change floor threshold
 */
-(void)setDistanceToChangeFloorThreshold:(NSInteger)distanceToChangeFloorThreshold;

@end
#endif
