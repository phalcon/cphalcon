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

namespace Phalcon\Tests\Unit\Crypt;

use UnitTester;

class SetAuthTagCest
{
    /**
     * Unit Tests Phalcon\Crypt :: setAuthTag()
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2019-05-25
     */
    public function cryptSetAuthTag(UnitTester $I)
    {
        $I->wantToTest('Crypt - setAuthTag()');

        $I->skipTest('Need implementation');
    }
}
