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

namespace Phalcon\Test\Controllers;

class AboutController
{
    /**
     * @Get("/about/team")
     */
    public function teamAction()
    {
    }

    /**
     * @Post("/about/team")
     */
    public function teamPostAction()
    {
    }
}
