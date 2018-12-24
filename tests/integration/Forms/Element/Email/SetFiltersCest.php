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

namespace Phalcon\Test\Integration\Forms\Element\Email;

use IntegrationTester;

/**
 * Class SetFiltersCest
 */
class SetFiltersCest
{
    /**
     * Tests Phalcon\Forms\Element\Email :: setFilters()
     *
     * @param IntegrationTester $I
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2018-11-13
     */
    public function formsElementEmailSetFilters(IntegrationTester $I)
    {
        $I->wantToTest('Forms\Element\Email - setFilters()');
        $I->skipTest('Need implementation');
    }
}
