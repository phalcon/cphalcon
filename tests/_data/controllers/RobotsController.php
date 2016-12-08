<?php

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
