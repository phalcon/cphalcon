<?php

namespace Phalcon\Test\Unit\Mvc\View\Engine\Volt\Compiller\Statements;

use Phalcon\Test\Module\UnitTest;
use Phalcon\Mvc\View\Engine\Volt\Compiler;
use Phalcon\Test\Unit\Mvc\View\Engine\Volt\CompilerTrait;

class SwitchCaseTest extends UnitTest
{
    use CompilerTrait;

    protected $cache = [
        'views/filters/default.volt.php',
    ];

    /** @test */
    public function shouldRecognizeEmptySwitch()
    {
        $this->specify(
            "The Volt compiller desn't valid switch-case statement",
            function () {
                $volt = new Compiler();

                $view = env('PATH_DATA') . 'views/switch-case/simple-usage.volt';
                $volt->compileFile($view, $view . '.php');

                $compilation = file_get_contents($view . '.php');
                $expected = "<?php switch (\$username): ?>\n" .
                            "<?php case 'Jim': ?>\n" .
                            "Hello username\n" .
                            "<?php case 'Nik': ?>\n" .
                            "<?= \$username ?>!\n" .
                            "<?php break; ?>\n" .
                            "<?php default: ?>\n" .
                            "Who are you?\n" .
                            "<?php endswitch ?>\n";

                expect($compilation)->same($expected);
            }
        );
    }
}
