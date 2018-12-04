#import "VidyoIOPlugin.h"
#import "VidyoViewController.h"

@implementation VidyoIOPlugin

- (void)pluginInitialize {
    // Register the application default settings from the Settings.bundle to the NSUserDefaults object.
    // Here, the user defaults are loaded only the first time the app is loaded and run.
    
    NSUserDefaults *standardUserDefaults = [NSUserDefaults standardUserDefaults];
    
    NSString *settingsBundle = [[NSBundle mainBundle] pathForResource:@"Settings" ofType:@"bundle"];
    if (!settingsBundle) {
        NSLog(@"Could not find Settings.bundle");
    } else {
        NSDictionary *settings = [NSDictionary dictionaryWithContentsOfFile:[settingsBundle stringByAppendingPathComponent:@"Root.plist"]];
        NSArray *preferences = [settings objectForKey:@"PreferenceSpecifiers"];
        
        for (NSDictionary *prefSpecification in preferences) {
            NSString *key = [prefSpecification objectForKey:@"Key"];
            if (key) {
                // Check if this key was already registered
                if (![standardUserDefaults objectForKey:key]) {
                    [standardUserDefaults setObject:[prefSpecification objectForKey:@"DefaultValue"] forKey:key];
                    
                    NSLog( @"writing as default %@ to the key %@", [prefSpecification objectForKey:@"DefaultValue"], key );
                }
            }
        }
    }
}

- (void)launchVidyoIO:(CDVInvokedUrlCommand *)command {
    NSString* token = [command.arguments objectAtIndex:0];
    NSString* host = [command.arguments objectAtIndex:1];
    NSString* displayName = [command.arguments objectAtIndex:2];
    NSString* resourceId = [command.arguments objectAtIndex:3];
    
    NSUserDefaults *standardUserDefaults = [NSUserDefaults standardUserDefaults];
    
    if (token != nil) {
        [standardUserDefaults setObject:token forKey:@"token"];
    }
    
    if (host != nil) {
        [standardUserDefaults setObject:host forKey:@"host"];
    }
    
    if (displayName != nil) {
        [standardUserDefaults setObject:displayName forKey:@"displayName"];
    }
    
    if (resourceId != nil) {
        [standardUserDefaults setObject:resourceId forKey:@"resourceId"];
    }
    
    [standardUserDefaults setBool:YES forKey:@"autoJoin"];
    [standardUserDefaults setBool:YES forKey:@"hideConfig"];
    
    UIStoryboard *storyboard = [UIStoryboard storyboardWithName:@"Vidyo" bundle:nil];
    self.vidyoViewController = [storyboard instantiateViewControllerWithIdentifier:@"VidyoViewController"];
        
    if(self.vidyoViewController == nil) {
        self.vidyoViewController = [[VidyoViewController alloc] init];
    
        self.vidyoViewController.plugin = self;
    }
    
    [self.viewController presentViewController:self.vidyoViewController animated:YES completion:nil];
}

- (void)destroy {
    self.vidyoViewController.plugin = nil;
    self.vidyoViewController = nil;
}

@end

