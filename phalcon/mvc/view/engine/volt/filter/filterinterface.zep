namespace Phalcon\Mvc\View\Engine\Volt\Filter;

interface FilterInterface
{
	/**
	 * Filters a value
	 */
	public function filter(value) -> string;
}
