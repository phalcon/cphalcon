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

namespace Phalcon\Test\Integration\Mvc\View;

use IntegrationTester;

/**
 * Class SetTemplateAfterCest
 */
class SetTemplateAfterCest
{
    /**
     * Tests Phalcon\Mvc\View :: setTemplateAfter()
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2018-11-13
     */
    public function mvcViewSetTemplateAfter(IntegrationTester $I)
    {
        $I->wantToTest('Mvc\View - setTemplateAfter()');
        $I->skipTest('Need implementation');
    }
}
