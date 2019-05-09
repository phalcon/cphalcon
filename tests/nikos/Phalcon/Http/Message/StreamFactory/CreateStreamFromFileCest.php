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

namespace Phalcon\Test\Unit\Http\Message\StreamFactory;

use UnitTester;

class CreateStreamFromFileCest
{
    /**
     * Tests Phalcon\Http\Message\StreamFactory :: createStreamFromFile()
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2019-05-07
     */
    public function httpMessageStreamFactoryCreateStreamFromFile(UnitTester $I)
    {
        $I->wantToTest('Http\Message\StreamFactory - createStreamFromFile()');

        $I->skipTest('Need implementation');
    }
}
