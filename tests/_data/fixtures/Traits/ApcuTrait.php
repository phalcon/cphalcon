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

namespace Phalcon\Tests\Fixtures\Traits;

use UnitTester;

trait ApcuTrait
{
    public function _before(UnitTester $I)
    {
        $I->checkExtensionIsLoaded('apcu');
    }
}
