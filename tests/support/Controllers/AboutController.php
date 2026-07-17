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

namespace Phalcon\Tests\Support\Controllers;

use Phalcon\Annotations\Router\Get;
use Phalcon\Annotations\Router\Post;

class AboutController
{
    /**
     * @Get("/about/team")
     */
    #[Get("/about/team")]
    public function teamAction()
    {
    }

    /**
     * @Post("/about/team")
     */
    #[Post("/about/team")]
    public function teamPostAction()
    {
    }
}
