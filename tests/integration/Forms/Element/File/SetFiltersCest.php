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

namespace Phalcon\Test\Integration\Forms\Element\File;

use IntegrationTester;

/**
 * Class SetFiltersCest
 */
class SetFiltersCest
{
    /**
     * Tests Phalcon\Forms\Element\File :: setFilters()
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2018-11-13
     */
    public function formsElementFileSetFilters(IntegrationTester $I)
    {
        $I->wantToTest('Forms\Element\File - setFilters()');
        $I->skipTest('Need implementation');
    }
}
