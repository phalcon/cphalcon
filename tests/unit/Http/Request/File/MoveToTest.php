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

namespace Phalcon\Tests\Unit\Http\Request\File;

use Phalcon\Http\Request\File;
use Phalcon\Tests\AbstractUnitTestCase;
use Phalcon\Tests\Support\Page\Http;

use function outputDir;
use function supportDir;

final class MoveToTest extends AbstractUnitTestCase
{
    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2018-11-13
     */
    public function testHttpRequestFileMoveTo(): void
    {
        $file = new File(
            [
                'name'     => 'test',
                'type'     => Http::CONTENT_TYPE_PLAIN,
                'tmp_name' => supportDir('/assets/images/example-jpg.jpg'),
                'size'     => 1,
                'error'    => 0,
            ]
        );

        // moveTo() delegates to move_uploaded_file(), which only succeeds
        // for genuine HTTP-uploaded files (per is_uploaded_file()).
        // Outside a real upload context it emits a warning and returns
        // false - silence the warning and assert the return value.
        $destination = outputDir('tests/' . uniqid('move-', true) . '.txt');

        $previous = error_reporting(0);
        try {
            $result = $file->moveTo($destination);
        } finally {
            error_reporting($previous);
        }

        $this->assertFalse($result);
        $this->assertFileDoesNotExist($destination);
    }
}
