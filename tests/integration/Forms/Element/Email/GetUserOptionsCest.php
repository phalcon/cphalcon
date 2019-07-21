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
 * Class GetUserOptionsCest
 */
class GetUserOptionsCest
{
    /**
     * Tests Phalcon\Forms\Element\Email :: getUserOptions()
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2018-11-13
     */
    public function formsElementEmailGetUserOptions(IntegrationTester $I)
    {
        $I->wantToTest('Forms\Element\Email - getUserOptions()');
        $I->skipTest('Need implementation');
    }
}
