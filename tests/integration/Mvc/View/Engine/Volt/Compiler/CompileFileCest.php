<?php
declare(strict_types=1);

/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalconphp.com>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Test\Integration\Mvc\View\Engine\Volt\Compiler;

use IntegrationTester;
use Phalcon\Mvc\View\Engine\Volt\Compiler;

/**
 * Class CompileFileCest
 */
class CompileFileCest
{
    /**
     * Tests Phalcon\Mvc\View\Engine\Volt\Compiler :: compileFile()
     *
     * @param IntegrationTester $I
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2017-01-17
     */
    public function mvcViewEngineVoltCompilerCompileFile(IntegrationTester $I)
    {
        $I->wantToTest("Mvc\View\Engine\Volt\Compiler - compileFile()");
        $viewFile    = dataFolder('fixtures/views/layouts/compiler.volt');
        $compileFile = $viewFile . '.php';
        $expected    = '<?php if ($some_eval) { ?>
Clearly, the song is: <?= $this->getContent() ?>.
<?php } ?>';

        $volt = new Compiler();
        $volt->compileFile($viewFile, $compileFile);

        $actual = file_get_contents($compileFile);
        $I->assertEquals($expected, $actual);
        $I->safeDeleteFile($compileFile);
    }

    /**
     * Tests Phalcon\Mvc\View\Engine\Volt\Compiler :: compileFile()
     *
     * @param IntegrationTester $I
     *
     * @issue https://github.com/phalcon/cphalcon/issues/13242
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2018-11-13
     */
    public function mvcViewEngineVoltCompilerCompileFileDefaultFilter(IntegrationTester $I)
    {
        $examples = [
            'default'             => "<?= (empty(\$robot->price) ? (10.0) : (\$robot->price)) ?>\n",
            'default_json_encode' => "<?= json_encode((empty(\$preparedParams) ? ([]) : (\$preparedParams))) ?>\n",
        ];

        foreach ($examples as $view => $expected) {
            $volt         = new Compiler();
            $viewFile     = sprintf('%sfixtures/views/filters/%s.volt', dataFolder(), $view);
            $compiledFile = $viewFile . '.php';
            $volt->compileFile($viewFile, $compiledFile);

            $actual = file_get_contents($compiledFile);
            $I->assertEquals($expected, $actual);
            $I->safeDeleteFile($compiledFile);
        }
    }
}
