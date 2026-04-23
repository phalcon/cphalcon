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

namespace Phalcon\Tests\Database\Mvc\Model\Behavior\Timestampable;

use Phalcon\Mvc\Model\Behavior\Timestampable;
use Phalcon\Tests\AbstractDatabaseTestCase;
use Phalcon\Tests\Support\Models\Users;

final class MissingMethodTest extends AbstractDatabaseTestCase
{
    /**
     * @author Sid Roberts <https://github.com/SidRoberts>
     * @since  2019-06-03
     */
    public function testMvcModelBehaviorTimestampableMissingMethod(): void
    {
        $user     = new Users();
        $behavior = new Timestampable();
        $this->assertNull(
            $behavior->missingMethod($user, 'somethingAmazing', [])
        );
    }
}
