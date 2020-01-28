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

namespace Phalcon\Test\Integration\Mvc\View\Engine\Volt\Compiler;

use IntegrationTester;
use Phalcon\Mvc\View\Engine\Volt\Compiler;

class CompileIfCest
{
    /**
     * Tests Phalcon\Mvc\View\Engine\Volt\Compiler :: compileIf()
     *
     * @author Sid Roberts <https://github.com/SidRoberts>
     * @since  2019-05-22
     */
    public function mvcViewEngineVoltCompilerCompileIf(IntegrationTester $I)
    {
        $I->wantToTest('Mvc\View\Engine\Volt\Compiler - compileIf()');

        $volt = new Compiler();

        $compiled = $volt->compileString(
            '{% if i == 0 %}zero{% else %}not zero{% endif %}'
        );

        $I->assertEquals(
            '<?php if ($i == 0) { ?>zero<?php } else { ?>not zero<?php } ?>',
            $compiled
        );
    }
}
