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

namespace Phalcon\Test\Unit\Annotations\Reader;

use UnitTester;

class ParseDocBlockCest
{
    /**
     * Tests Phalcon\Annotations\Reader :: parseDocBlock()
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2018-11-13
     */
    public function annotationsReaderParseDocBlock(UnitTester $I)
    {
        $I->wantToTest('Annotations\Reader - parseDocBlock()');

        $I->skipTest('Need implementation');
    }
}
