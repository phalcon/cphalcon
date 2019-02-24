namespace Phalcon\Di;

use Phalcon\DiInterface;

interface PresetInterface
{
	public static function configure(<DiInterface> di, bool force = true);
}
