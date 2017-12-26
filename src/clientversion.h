#ifndef CLIENTVERSION_H
#define CLIENTVERSION_H

//
// client versioning
//

// These need to be macros, as version.cpp's and fef.rc's voodoo requires it
#define CLIENT_VERSION_MAJOR       1
#define CLIENT_VERSION_MINOR       2
#define CLIENT_VERSION_REVISION    1
#define CLIENT_VERSION_BUILD       2

// Set to true for release, false for prerelease or test build
#define CLIENT_VERSION_IS_RELEASE  true

// Converts the parameter X to a string after macro replacement on X has been performed.
// Don't merge these into one macro!
#define STRINGIZE(X) DO_STRINGIZE(X)
#define DO_STRINGIZE(X) #X
#define PACKAGE_NAME   "FEF"
#define COPYRIGHT_YEAR 2016
/* Copyright holder(s) */
#define COPYRIGHT_HOLDERS_FINAL "The FEF Core developers"

/* Replacement for %s in copyright holders string */
#define COPYRIGHT_HOLDERS_SUBSTITUTION "FEF Core"
/* Copyright holder(s) before %s replacement */
#define COPYRIGHT_HOLDERS "The %s developers"
#endif // CLIENTVERSION_H
