namespace Phalcon\Mvc\View\Engine\Volt\Filter;


use Phalcon\Filter\UserFilterInterface;
/**
 * Phalcon\Mvc\View\Engine\Volt\Filter\Sanitize
 *
 *<code>
 *  $compiler = new \Phalcon\Mvc\View\Engine\Volt\Filter\Sanitize();
 *  $compiler->filter('<html><body></body></html>');
 *</code>
 */
class Sanitize extends UserFilterInterface
{

    protected function filter(viewCode) {
        let search = [
            '/\>\r?\n\s*(\r?\n)?/',  // strip whitespaces after tags, except space
            '/[^\S ]+\</s',  // strip whitespaces before tags, except space
            '/(\s)+/s'       // shorten multiple whitespace sequences
        ];
        let replace = [
            '>',
            '<',
            '\\1'
        ];
        

        return preg_replace(search, replace, viewCode));
    }

}