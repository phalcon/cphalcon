<?php

namespace Phalcon\Test\Unit\Mvc\View\Engine\Volt\Compiller\Statements;

use Phalcon\Test\Module\UnitTest;
use Phalcon\Mvc\View\Engine\Volt\Compiler;

class SwitchCaseTest extends UnitTest
{
    protected function _before()
    {
        $cache = [
            'views/switch-case/simple-usage.volt.php',
        ];

        foreach ($cache as $file) {
            if (file_exists(PATH_DATA . $file)) {
                unlink(PATH_DATA . $file);
            }
        }
    }

    /** @test */
    public function shouldRecognizeEmptySwitch()
    {
        $this->specify(
            "The Volt compiller desn't valid switch-case statement",
            function () {
                $volt = new Compiler();

                $volt->compileFile(
                    PATH_DATA . 'views/switch-case/simple-usage.volt',
                    PATH_DATA . 'views/switch-case/simple-usage.volt.php'
                );

                $compilation = file_get_contents(PATH_DATA . 'views/switch-case/simple-usage.volt.php');
                $expected =<<<TPL
<?php switch (\$username): ?>
<?php case 'Jim': ?>
Hello username
<?php case 'Nik': ?>
<?= \$username ?>!
<?php break; ?>
<?php default: ?>
Who are you?
<?php endswitch ?>\n
TPL;

                expect($compilation)->same($expected);
            }
        );
    }
}
