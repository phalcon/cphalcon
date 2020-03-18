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

namespace Phalcon\Test\Unit\Http\Request\File;

use Phalcon\Http\Request\File;
use UnitTester;

use function dataDir;

class GetKeyCest
{
    /**
     * Tests Phalcon\Http\Request\File :: getKey()
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2020-03-17
     */
    public function httpRequestFileGetKey(UnitTester $I)
    {
        $I->wantToTest('Http\Request\File - getKey()');


        $file = new File(
            [
                'name'     => 'test',
                'type'     => 'text/plain',
                'tmp_name' => dataDir('/assets/images/phalconphp.jpg'),
                'size'     => 1,
                'error'    => 0,
            ],
            'abcde'
        );

        $I->assertEquals('abcde', $file->getKey());
    }
}
