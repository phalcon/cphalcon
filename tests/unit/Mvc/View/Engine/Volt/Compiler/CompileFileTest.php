<?php

/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

declare(strict_types=1);

namespace Phalcon\Tests\Unit\Mvc\View\Engine\Volt\Compiler;

use Phalcon\Mvc\View\Engine\Volt\Compiler;
use Phalcon\Tests\AbstractUnitTestCase;

class CompileFileTest extends AbstractUnitTestCase
{
    public static function defaultFilterProvider(): array
    {
        return [
            [
                'default',
                "<?= (empty(\$robot->price) ? (10.0) : (\$robot->price)) ?>\n",
            ],

            [
                'default_json_encode',
                "<?= json_encode((empty(\$preparedParams) ? ([]) : (\$preparedParams))) ?>\n",
            ],
        ];
    }

    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2017-01-17
     */
    public function testMvcViewEngineVoltCompilerCompileFile(): void
    {
        $viewFile    = supportDir('assets/views/layouts/compiler.volt');
        $compileFile = $viewFile . '.php';

        $expected = '<?php if ($some_eval) { ?>
Clearly, the song is: <?= $this->getContent() ?>.
<?php } ?>';

        $volt = new Compiler();

        $volt->compileFile($viewFile, $compileFile);
        $this->assertFileContentsEqual($compileFile, $expected);

        $this->safeDeleteFile($compileFile);
    }

    /**
     * @dataProvider defaultFilterProvider
     *
     * @issue https://github.com/phalcon/cphalcon/issues/13242
     * @author       Phalcon Team <team@phalcon.io>
     * @since        2018-11-13
     */
    public function testMvcViewEngineVoltCompilerCompileFileDefaultFilter(
        string $view,
        string $expected
    ): void {
        $volt = new Compiler();

        $viewFile = sprintf(
            '%sassets/views/filters/%s.volt',
            supportDir(),
            $view
        );

        $compiledFile = $viewFile . '.php';

        $volt->compileFile($viewFile, $compiledFile);

        $this->assertFileContentsEqual($compiledFile, $expected);

        $this->safeDeleteFile($compiledFile);
    }
}
