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

namespace Phalcon\Test\Unit\Messages\Message;

use Phalcon\Messages\Message;
use UnitTester;

/**
 * Class GetSetMetaDataCest
 */
class GetSetMetaDataCest
{
    /**
     * Tests Phalcon\Messages\Message :: getMetaData()/setMetaData()
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2019-02-10
     */
    public function messagesMessageGetSetMetaData(UnitTester $I)
    {
        $I->wantToTest('Messages\Message - getMetaData()/setMetaData()');
        $message = new Message(
            'This is a message #1',
            'MyField',
            'MyType',
            111,
            ['My1' => 'Metadata1']
        );

        $expected = ['My1' => 'Metadata1'];
        $actual   = $message->getMetaData();
        $I->assertEquals($expected, $actual);

        $expected = ['My2' => 'Metadata2'];
        $message->setMetaData($expected);
        $actual   = $message->getMetaData();
        $I->assertEquals($expected, $actual);
    }
}
