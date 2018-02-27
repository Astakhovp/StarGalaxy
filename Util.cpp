#include "Util.h"

boost::uuids::uuid generate_guid()
{
	return boost::uuids::random_generator()();
}
