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

namespace Phalcon\Test\Unit\Image\Adapter\Gd;

use UnitTester;

/**
 * Class GetMimeCest
 */
class GetMimeCest
{
    /**
     * Tests Phalcon\Image\Adapter\Gd :: getMime()
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2018-11-13
     */
    public function imageAdapterGdGetMime(UnitTester $I)
    {
        $I->wantToTest('Image\Adapter\Gd - getMime()');
        $I->skipTest('Need implementation');
    }
}
