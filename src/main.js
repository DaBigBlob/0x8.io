export default {
    async fetch() {
      return new Response(__HTML__, {
        headers: {
            "content-type": "text/html; charset=utf-8",
            "lmao": "lol even"
        },
        status: 200
      });
    },
  };
  