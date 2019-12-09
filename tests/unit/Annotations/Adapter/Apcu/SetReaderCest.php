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

namespace Phalcon\Test\Unit\Annotations\Adapter\Apcu;

use UnitTester;

class SetReaderCest
{
    /**
     * Tests Phalcon\Annotations\Adapter\Apcu :: setReader()
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2018-11-13
     */
    public function annotationsAdapterApcuSetReader(UnitTester $I)
    {
        $I->wantToTest('Annotations\Adapter\Apcu - setReader()');

        $I->skipTest('Need implementation');
    }
}
