<?php

declare(strict_types=1);

/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Test\Controllers;

/**
 * @RoutePrefix("/robots")
 */
class RobotsController
{
    /**
     * @Get("/")
     */
    public function indexAction()
    {
    }

    /**
     * @Get("/edit/{id:[0-9]+}", name="edit-robot")
     * @param int $id
     */
    public function editAction($id)
    {
    }

    /**
     * @Route("/save", methods={"POST", "PUT"}, name="save-robot")
     */
    public function saveAction()
    {
    }
}
