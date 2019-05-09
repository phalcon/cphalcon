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

namespace Phalcon\Test\Unit\Forms\Element\Email;

use UnitTester;

class GetMessagesCest
{
    /**
     * Tests Phalcon\Forms\Element\Email :: getMessages()
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2019-05-07
     */
    public function formsElementEmailGetMessages(UnitTester $I)
    {
        $I->wantToTest('Forms\Element\Email - getMessages()');

        $I->skipTest('Need implementation');
    }
}
