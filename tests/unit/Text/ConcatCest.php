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

namespace Phalcon\Tests\Unit\Text;

use Phalcon\Text;
use UnitTester;

class ConcatCest
{
    /**
     * Tests Phalcon\Text :: concat()
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2018-11-13
     */
    public function textConcat(UnitTester $I)
    {
        $I->wantToTest('Text - concat()');

        // Test 1
        $I->assertEquals(
            '/tmp/folder_1/folder_2/folder_3/',
            Text::concat('/', '/tmp/', '/folder_1/', '/folder_2', 'folder_3/')
        );

        // Test 2
        $I->assertEquals(
            '@test.test2.test.34',
            Text::concat('.', '@test.', '.test2.', '.test', '.34')
        );
    }
}
