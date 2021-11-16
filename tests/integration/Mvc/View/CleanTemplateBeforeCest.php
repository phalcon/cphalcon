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

namespace Phalcon\Tests\Integration\Mvc\View;

use IntegrationTester;

/**
 * Class CleanTemplateBeforeCest
 */
class CleanTemplateBeforeCest
{
    /**
     * Tests Phalcon\Mvc\View :: cleanTemplateBefore()
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2018-11-13
     */
    public function mvcViewCleanTemplateBefore(IntegrationTester $I)
    {
        $I->wantToTest('Mvc\View - cleanTemplateBefore()');
        $I->skipTest('Need implementation');
    }
}
