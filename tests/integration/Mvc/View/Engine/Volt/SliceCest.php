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

namespace Phalcon\Test\Integration\Mvc\View\Engine\Volt;

use IntegrationTester;

/**
 * Class SliceCest
 */
class SliceCest
{
    /**
     * Tests Phalcon\Mvc\View\Engine\Volt :: slice()
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2018-11-13
     */
    public function mvcViewEngineVoltSlice(IntegrationTester $I)
    {
        $I->wantToTest('Mvc\View\Engine\Volt - slice()');
        $I->skipTest('Need implementation');
    }
}
