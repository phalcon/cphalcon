<?php

namespace Phalcon\Test\Unit\Mvc\View\Engine\Volt\Compiller\Filters;

use Phalcon\Test\Module\UnitTest;
use Phalcon\Mvc\View\Engine\Volt\Compiler;
use Phalcon\Test\Unit\Mvc\View\Engine\Volt\CompilerTrait;

class DefaultTest extends UnitTest
{
    use CompilerTrait;

    protected $cache = [
        'views/filters/default.volt.php',
    ];

    /**
     * @test
     * @todo Move this test to tests/syntax suite
     */
    public function shouldParseDefaulFilter()
    {
        $this->specify(
            'Unable to parse "default" filter',
            function () {
                $volt = new Compiler();

                $intermediate = $volt->parse('{{ robot.price|default(10.0) }}');

                expect(is_array($intermediate))->true();
                expect($intermediate)->count(1);
            }
        );
    }

    /**
     * @test
     * @issue https://github.com/phalcon/cphalcon/issues/13242
     */
    public function shouldCompileDefaulFilter()
    {
        $this->specify(
            'Unable to compile "default" filter',
            function () {
                $volt = new Compiler();

                $view = env('PATH_DATA') . 'views/filters/default.volt';
                $volt->compileFile($view, $view . '.php');

                $compilation = file_get_contents($view . '.php');
                $expected = "<?= (empty(\$robot->price) ? (10.0) : (\$robot->price)) ?>\n";

                expect($compilation)->same($expected);


                $view = env('PATH_DATA') . 'views/filters/default_json_encode.volt';
                $volt->compileFile($view, $view . '.php');

                $compilation = file_get_contents($view . '.php');
                $expected = "<?= json_encode((empty(\$preparedParams) ? ([]) : (\$preparedParams))) ?>\n";

                expect($compilation)->same($expected);
            }
        );
    }
}
