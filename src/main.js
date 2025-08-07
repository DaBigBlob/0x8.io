
export default {
    async fetch(req, env) {
        return new Response(
            env.PUB.fetch(`${req.url}/index.html`),
            {headers: {"content-type": "text/html"}, status: 200}
        );
    }
};