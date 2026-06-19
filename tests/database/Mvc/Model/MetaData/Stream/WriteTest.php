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

namespace Phalcon\Tests\Database\Mvc\Model\MetaData\Stream;

use Phalcon\Mvc\Model\Exception;
use Phalcon\Mvc\Model\MetaData\Stream;
use Phalcon\Tests\AbstractDatabaseTestCase;
use Phalcon\Tests\Support\Models\Robots;
use Phalcon\Tests\Support\Traits\DiTrait;
use PHPUnit\Framework\Attributes\Group;

use function file_exists;
use function file_put_contents;
use function unlink;

#[Group('mysql')]
#[Group('pgsql')]
#[Group('sqlite')]
final class WriteTest extends AbstractDatabaseTestCase
{
    use DiTrait;

    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2018-11-13
     */
    public function testMvcModelMetadataStreamWrite(): void
    {

        $this->markTestSkipped('Need implementation');
    }
}
